#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
12:53

<문제>
어떤 수에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 수 구하기
숫자 number, 제거할 수 개수 k주어지면
만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return

number는 2자리 이상, 100만자리 이하 수
k는 1이상, number의 자리 수 미만인 자연수

<풀이>

2시간 제한 시간 초과로 답지를 봄


<시간>
O(100만*100만) -> 가능한 거 맞을까?? 제한이 없긴 해..
*/

using namespace std; 

//안쓰는 함수
//cur_num에서의 최대 값 구하기 - k번 더 뺄 수 있는 상황
string getMax(string cur_num, int k){
    if(k<=0) return cur_num;
    
    
    
    string maxx = getMax(cur_num.substr(1), k-1);    //첫번째 문자 뺀 경우
    
    //하나씩 빼서 재귀로 최댓값 찾기
    for(int i=1; i< cur_num.size(); i++){
        string target = getMax(cur_num.substr(0, i) + cur_num.substr(i+1), k-1);
        if(maxx < target){  //새로 뺀 문장이 더 큰 경우 -> 업데이트
            maxx = target;
        }
        
    }
    
    return maxx;
}

string solution(string number, int k) {
    string answer = "";
 
    int numSize = number.size() - k;
    int start = 0;
    for(int i=0; i<numSize; i++) {
        char maxNum = number[start];
        int maxIdx = start;
        for(int j=start; j<=k+i; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }
 
    return answer;
}

/*

<의식의 흐름>

가장 앞에서 가장 작은 수 2개를 빼면 될 거 같은디

number 복사 후 자릿수 별 정렬
k번 반복
  가장 작은 수 골라내기
  그 수를 앞에서 부터 탐색하면서 삭제(number에서 처리)

number return

시간 :O(100만)
-> 테케 3번 미통과 -> 반례 존재 -> 다시 짜기


모든 경우의 수 조사


k번 반복
    maxx = 0번째 뺀 숫자값 저장
    1번째부터 number.size()번째 전까지 i로 반복
        if(maxx < i번째 뺀 숫자)
          maxx값 업데이트
    cur_num = maxx로 업데이트

return cur_num

-> 테케 6, 7, 8, 9, 10 시간초과 뜸 (나머진 정답) -> 재귀로 짜보자 


재귀로 짜보기
k개 수가 빠질 때 까지 재귀로 계속 숫자 빼기
그래서 최종 리턴값들 비교

 -> 테케 1, 11, 22 맞고 나머지 시간초과 남 ㅠ
재귀로 했는데도 안된다... 사실 시간복잡도를 계산을 안하고 파고들었는데 앞으로 역시 해야겠다

*/
