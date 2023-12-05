#include <string>
#include <vector>

using namespace std;
/*
<문제>
numbers 숫자배열로 target(int) 만들기

숫자를 적절히 더하고 빼서 타겟넘버를 만드는 방법의 수 return

numbers 길이 <= 20
각 숫자 <= 50
타겟 넘버 <= 1000

<풀이>
더하기를 할 경우와, 빼기를 할 경우를 나누어서 재귀로 구현

<시간>
쌉가능 - 1000 * log(1000)

*/

vector<int> number;
int target_num;

//현재 number위치, 현재 합을 인자로 넣어서, 최종 답 알아내기
int getAns(int cur_num, int cur_sum, int cur_ans){
    
    //마지막 숫자일 때 - 마지막숫자 처리하고 끝내면서 타겟넘버와 일치여부에 따라 계산
    if(cur_num>=(number.size()-1)){
        
        if(target_num == (cur_sum + number[cur_num]) )  cur_ans++;
        else if(target_num == (cur_sum - number[cur_num]) ) cur_ans++;
        return cur_ans;
    }
    
    //마지막이 아님 -> -로 작용했을 때랑
    return getAns(cur_num+1, cur_sum+number[cur_num], cur_ans)
                + getAns(cur_num+1, cur_sum-number[cur_num], cur_ans);
    
}

int solution(vector<int> numbers, int target) {
    
    for(int i=0; i<numbers.size(); i++){    //일단 전역변수로 빼기
        number.push_back(numbers[i]);
    }
    target_num = target;
    

    return getAns(0, 0, 0);
}
