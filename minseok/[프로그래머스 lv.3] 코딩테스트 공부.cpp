#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
/*
<문제>
알고력, 코딩력 - 0이상 정수
각각 1 높이기 위해선 1의 시간 필요
현재 풀 수 있는 문제중 하나를 풀어 알고력 코딩력을 높임 - 각 문제를 풀면 올라가는 알고력, 코딩력 정해져있음

주어진 모든 문제들을 풀 수 있느 알고력, 코딩력을 얻는 최단시간 구하기

초기 alp, cop, problems(문제의 정보 - 2차원배열) 
모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 return
모든 문제들을 한 번 이상씩 풀 필요는 없음

alp, cop <=150
problems 길이 <=100 / [alp_req, cop_req, alp_rwd, cop_rwd, cost] 형태로 이루어짐


<풀이>
1. DP 떠올리기
 -> dp[a][b] : 알고력 a, 코딩력 b를 얻기 위해 필요한 최소시간
 
2. dp값을 어떻게 구해나갈 것인지 구체화하기
* dp값 모두 INF 설정 / alp, cop계산 과정들에서 max값 안넘어가도록 주의

[alp][cop]부터 (i, j) 반복문 순차적으로 수행,
  dp[i+1][j], dp[i][j+1]을 해당 단계에서 공부하는 경우랑 기존 dp값 대체해서 비교 - 최솟값으로 설정
  이후 문제들 반복
    풀 수 있는 문제들 판별
      해당문제를 풀었을 경우의 dp[new_alp][new_cop]를 기존의 dp값과 비교해서 알맞게 설정

<시간>
O(alp * cop * problems)

*/
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int dp[151][151];  //dp[a][b] : 알고력 a, 코딩력 b를 얻기 위해 필요한 최소시간
  
    int max_alp=0, max_cop=0;   // 최대 요구 역량
    
    //최대 요구 알고력, 코딩력 설정 -> 추후 dp[max_alp][max_cop]를 계산하면 됨 
    for(int i=0; i<problems.size(); i++){
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        
        max_alp = max(alp_req, max_alp);
        max_cop = max(cop_req, max_cop);
    }
    
    //dp 모든 값 INF로 초기화
    for(int i=0; i<=150; i++){
        for(int j=0; j<=150; j++){
            dp[i][j]=INF;      //모두 최대값으로 설정
        }
    }
    
    alp = min(alp, max_alp); cop = min(cop, max_cop);
    //요구하는 역량을 초기에 달성한 경우를 처리하기 위해 설정
    
    dp[alp][cop] = 0;   //초기설정
    
    for(int i=alp; i<=max_alp; i++){
        for(int j=cop; j<=max_cop; j++){
            //i : 현재 알고력, j : 현재 코딩력
            if(i < max_alp){    //알고력 부족한 경우
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
                //직접 공부해서 채우는 것과, dp값 중 비교해서 최솟값
            }
            if(j < max_cop){    //코딩력 부족한 경우
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
                //직접 공부해서 채우는 것과, dp값 중 비교해서 최솟값
            }
            //1회 dp 계산 완료 - 풀 수 있는 문제가 나오기 전까지는 모두 다 공부해서 채우게 될 것임
            
            
            for(int k=0; k<problems.size(); k++){   
                //해당 알고력에서 풀 수 있는 모든 문제들에 대해 진행
                //문제들을 다 돌면서 풀 수 있는 문제들에 대해 dp 업데이트
                if(i>=problems[k][0] && j>=problems[k][1]){   //알고력, 코딩력이 해당 문제를 풀 수 있는 경우
                    
                    //변수 설정
                    int alp_req = problems[k][0];
                    int cop_req = problems[k][1];
                    int alp_rwd = problems[k][2];
                    int cop_rwd = problems[k][3];
                    int cost = problems[k][4];            
                    
                    //문제를 풀었을 경우의 new_alp, new_cop 설정
                    //현재알고력 + reward / 현재코딩력 + reward
                    //목표값이 넘어가는 것을 방지하기 위해 min 사용
                    int new_alp = min(i+alp_rwd, max_alp);  
                    int new_cop = min(j+cop_rwd, max_cop);
                    
                    //1. 현재상황(dp[i][j])에서 문제를 풀 때의 dp[new_alp][new_cop]
                    //2. 기존의 경우의 dp[new_alp][new_cop] 
                    // -> 비교
                    dp[new_alp][new_cop] = min(dp[new_alp][new_cop], dp[i][j] + cost);
                }
            }
            //dp 수정 완료
            
        }
    }
    
    answer = dp[max_alp][max_cop];
    return answer;
}




/*
<의식의 흐름 - 기록용>

일단, cost >= alp_rwd + cop_rwd인 경우는 버려야 함 - 그냥 알고력 코딩력 올리면 이득이니까

일단 최대 알고력, 코딩력을 구해야 함 - 반복문 통해서

그리고 비용대비 얻는 알고력, 코딩력이 높은 과목을 계속 공부하면 되나?
 -> ㄴㄴ 얻어야 하는 알고력, 코딩력을 파악한 후, 부족한 항목을 보면서 공부해야 함

둘다 부족할 때
 - 공부 가능한 것 중 / 비용 대비 얻는 '알고력 + 코딩력'이 최대인 거
 - 없으면 공부로 올려서 공부 가능한 과목 만들기

하나만 부족할 때
 - 공부 가능한 것 중 / 비용 대비 얻는 '해당역량' 이 최대인 거
 - 없으면 공부로 올려서 공부 가능한 과목 만들기

직접 늘려야 하는 상황이 언제지? / 공부 가능한 것이 계속 달라짐

비용 대비 알고력 + 코딩력 높은 과목 선정
그걸 공부하려면 필요한 알고력, 코딩력 -> 여기에 최소시간으로 도달하기 위해 새로운 목표 설정
그 다음 비용대비 가치가 높은 과목 선정 -> 새로운 목표설정
-> 가능한 과목이 나올 때 까지 / 또는 아예 없거나

가능한 과목이 나오면 그거 학습 / 여러개면 다 재귀로 돌림

3가지 중 하나
1. 알고리즘 공부
2. 코딩 공부
3. 문제 풀이

현 상황 : 내 alp, cop 가 있고 / 도달해야 하는 max_alp, max_cop가 있음

공부를 해서 올려야 할지, 문제풀이를 해야할지를 실시간으로 결정할 수 있나?
 -> 이걸 모른다는게 지금 문제임
 
공부를 해야할 때가 언제지?
 더 효율이 좋은 과목을 공부하기 위해 올려야 하는데, 지금 가능한 문제를 풀이하는 것보다 공부해서 더 좋은과목 풀이하는게 이득일 때
 -> 이걸 어캐결정함
 Dp써야할거같은데
-> dp[a][b] : 알고력 a, 코딩력 b를 얻기 위해 필요한 최소시간 / 이렇게 설정해보면?

[alp][cop]부터 (i, j) 반복문 순차적으로 수행,
  dp[i+1][j], dp[i][j+1]을 해당 단계에서 공부하는 경우랑 기존 dp값 대체해서 비교 - 최솟값으로 설정
  이후 문제들 반복
    풀 수 있는 문제들에 대해
      해당문제를 풀었을 경우의 dp[new_alp][new_cop]를 기존의 dp값과 비교해서 알맞게 설정
*/
