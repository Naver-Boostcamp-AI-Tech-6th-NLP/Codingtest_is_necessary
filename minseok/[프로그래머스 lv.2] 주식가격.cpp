#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
/*
<문제>
초 단위 주식가격 배열 prices
가격이 떨어지지 않은 기간은 몇 초인지 return

prices각 가격 <= 10000
price 길이 <= 10만


<풀이>
각 배열마다, 그 원소 이상의 가격만 유지하면 됨

그냥 반복문 돌리면?
n^2이긴 한데, 시간제한이 왜 없징 -> 해도 되나?

prices원소마다 스택에 넣어가면서, 
이전 스택의 원소들보다 작은지를 확인해서 체크하기?

<시간>
O(100000^2)

*/
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++)
        answer.push_back(0);    //초기화
    
    
    stack<pair<int, int> > list;    //주식가격 리스트 - 값, 인덱스 로 넣기
    
    list.push(pair<int, int>(prices[0], 0));    //초기값 넣기
    
    
    int cur_time=1;  //현재 시간(현재 인덱스번호)
    //시간 증가시켜가면서, 배열의 원소들 처리
    while(!list.empty()){
        
        if(cur_time == prices.size()-1){  //마지막까지 온 경우
            while(!list.empty()){
                answer[list.top().second] = cur_time-list.top().second; //인덱스 계산
                list.pop();
            }
            return answer;
        }
        
        int target_val = prices[cur_time]; //현재 목표 값
        int target_index = cur_time;   //인덱스번호
        
        //스택 값 꺼내서 비교
        int stack_val = list.top().first;
        int stack_index = list.top().second;
        
        while(stack_val > target_val && !list.empty()){  //목표값보다 스택에 있는 값이 큰 경우 -> 시간계산 진행 및 pop
            
            //cout<<"계산진행 "<<stack_val << " "<< target_val<<endl;
            answer[stack_index] = target_index-stack_index;
            list.pop();
            
            //새로운 값 할당
            if(!list.empty()){
                stack_val = list.top().first;
                stack_index = list.top().second;
            }
        }
        list.push(pair<int, int>(target_val, target_index));
        cur_time++;
    }
    return answer;
}
