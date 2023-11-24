#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
11:20 ~ 11:58(40분)
문자열 요소 제거하는 메서드 잘못알아서 시간 잡아먹었음

<문제>
한자리 숫자의 종이조각 - 붙여서 소수를 몇개 만들 수 있는지 알아내기

숫자 문자열 numbers -> 만들 수 있는 소수 개수 return

numbers길이 : 1~7
numbers : 0~9까지 수
11과 011은 같은 숫자 취급


<풀이>
굳이 다 안써도 되는 듯
시간, 메모리제한 왜 없지?? - 진짜 막 한다?

그러면 그냥 소수 다 찾아내서 저장한 다음,
재귀로 모든 조합 돌려가면서 판별하면 될 거 같은디


<시간>
소수 판별 - O(N)
cntNum - O(N!)
겁나 오래걸리겠지만, 시간제한이 없어서 일단 진행..
*/

int dp[10000001];

bool isPrime(int n){    //소수판별하기
    
    if(dp[n]>=1) return false;  //방문한 소수면 또 셀 필요 없음
    if(n < 2) return false;
    
    dp[n]++;

    if(n==2) return true;
    
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }    
    return true;
}

//string 문자열에서 모든 경우의 수 고려해서 카운트하기 - 재귀
int cntNum(int cur_num, string numbers){
    
    int cnt = 0;
  
    //하나 남은 경우 - 더하고 결과리턴
    if(numbers.size()==1){
        cur_num*=10; cur_num+=numbers[0]-'0';   //문자열 추가
        
        if(isPrime(cur_num)) cnt++;
        return cnt;
    }
    else{   //문자열 여러개 남은 경우 - 하나하나 더해서 재귀로 넘기기

        for(int i=0; i<numbers.size(); i++){    //문자열 추가해서 보기
            int target = cur_num;   //현재 상황에서 재귀로 넘길 cur_num
            string numbers_target = numbers;    //복사해서 뺄 거 빼고 재귀로 넘길거
            
            target*=10; target+=numbers_target[i]-'0';   //문자열 숫자값 추가
            numbers_target.erase(i, 1);   //numbers에서 제거
            
            if(isPrime(target)) cnt++;
            cnt+=cntNum(target, numbers_target);
        }
        return cnt;
    }
}

int solution(string numbers) {
    int answer = 0;

    for(int i=0; i<10000000; i++)
        dp[i]=0;   //방문여부
    
    //numbers 모든 경우의 수 고려
    answer = cntNum(0, numbers);
    return answer;
}
