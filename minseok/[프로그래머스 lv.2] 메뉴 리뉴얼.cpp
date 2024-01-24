#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
/*
<문제>
단품으로 제공하던메뉴 조합해서 코스요리 형태로 재구성 -> 새로운 메뉴 제공
가장 많이 함께 주문했던 단품메뉴들을 코스요리 메뉴로 구성
최소 2가지 이상의 단품메뉴로 구성, 최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함
(각 손님은 단품메뉴 2개이상 주문 / 단품메뉴는 A~Z 알파벳 대문자)


각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders
추가하고 싶어하는 코스요리 구성 개수가 담긴 배열 course 주어짐

새로 추가하게 될 코스요리 메뉴 구성을 문자열 형태로 배열에 담아 return

orders 배열 크기 20 이하(각 문자열은 알파벳 대문자, 중복 x)
course 배열 크기 10 이하(2~10 자연수가 오름차순 정렬, 중복 x)

정답은 사전순 오름차순 정렬해서 return
가장 많이 함께 주문된 메뉴 구성이 여러개면, 모두 배열에 담아 return
(return값의 사이즈는 항상 1 이상이 되도록 주어짐)


<풀이>
orders 각 항목별로, 모든 조합(2, 3, 4개.. 모두)을 만들어서 세버리기 -> 2개 이상이면 채택
map을 이용해보자! - <key, value> / 레드블랙트리로 구현되어있고, 검색/삽입/삭제 -> O(logn)시간 걸림


<시간>
O(NlogN) -> 가능

*/


map<string, int> combination[11];   //조합 - combination[i] : i개를 뽑는 조합의 문자열들 저장
int max_cnt[11] = {0, };    //combiniation[i]에서 최고 등장 횟수


//order주어졋을 때, 해당 경우의 코스요리들 넣어주기 (partial : 현재 진행중인 문자열, index : 현재 인덱스)
void dfs(string order, string partial, int index){
    
    if(index >= order.size()) return;    //사이즈 넘어가면 종료
    
    dfs(order, partial, index+1);   //해당 문자를 안넣고 넘어간 경우
    
    partial += order[index];  //해당 문자 넣기
    combination[partial.size()][partial]++; //해당 부분 더하기(없으면 알아서 추가)
    
    //최고 등장횟수 갱신
    if(max_cnt[partial.size()] < combination[partial.size()][partial])
        max_cnt[partial.size()] = combination[partial.size()][partial];
    
    dfs(order, partial, index+1);   //해당 문자를 넣고 넘어간 경우
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;
    
    //orders별로 가능한 조합 찾아서, combination에 잘 넣어주기
    for(string order : orders){
        sort(order.begin(), order.end());
        dfs(order, "", 0);
    }   

    //max_cnt에 해당하는 것들만 출력
    for(int n : course){
        for(auto target : combination[n]){    //해당 개수에서의 최대 개수로 판단
            if(max_cnt[n] >= 2 && target.second == max_cnt[n]){
                answer.push_back(target.first);
            }
        }
    }
    
    //각 원소 정렬해주기
    for(string a : answer)
        sort(a.begin(), a.end());
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
