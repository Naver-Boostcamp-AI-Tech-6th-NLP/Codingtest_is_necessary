#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 987654321

using namespace std;
/*
<문제>
n개의 지점(1~n) - 출입구/쉼터/산봉우리 중 하나
각 지점은 양방향 통행 가능한 등산로로 연결 / 서로다른 지점 이동할 때 이 등산로 사용 - 각각 특정 시간 소요
등산코스 - 번호를 나열하여 표현가능
쉼터나 산봉우리 방문할 때마다 휴식 가능
휴식없이 이동해야하는 시간 중 가장 긴시간 = intensity

산의 출입구 중 한 곳에서 출발해서 산봉우리 중 하나만 방문한 뒤 다시 출입구로 돌아오는 등산코스 짤거
 -> 출입구는 처음 끝에 한번씩(같은 출입구여야 함), 산봉우리는 한번만 포함해야 함
 -> 그러면서 intensity 최소 되도록 등산코스 정하기

n <= 5만
paths 길이 <= 20만 [i, j, w] 형태 -> i, j 등산로 이동시간 w / 중복없음
w <= 1000만
gates <= n / 해당 지점이 출입구임을 나타냄
summits <= n / 해당 지점이 산봉우리임을 나타냄
 -> gates, summits에 등장하지 않은 지점은 모두 쉼터

return 배열 : [산봉우리 번호, intensity 최솟값] 순서여야함 / intensity 같으면 낮은 산봉우리 번호 출력



<풀이>
다익스트라 알고리즘 수행
단, gates를 동시에 출발 - 출입구가 어디인지는 상관이 없고, 
모든 출입구가 각 단계에서 인접노드의 최소 intensity를 수정해주기 때문에 서로 공유해서 최솟값 선정 가능

<시간>
O(|E|log|V|)
*/


struct Node{
    bool is_summit = false;    //산봉우리 여부 - true이면 여기서 다익스트라 끝낼거
    bool is_gate = false;   //출입구 여부 - true면 방문 안함
    vector<pair<int, int> > nearby; //근처 노드들 - 번호, 가중치로 구성
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    vector<Node> nodes;
    
    for(int i=0;i<=n; i++){
        Node a; nodes.push_back(a);    
    }//노드들 삽입 - n+1개([0] 미사용)
    
    //산봉우리 등록
    for(int i=0; i<summits.size(); i++){
        nodes[summits[i]].is_summit = true;
    } 
    
    
    //경로 및 가중치 등록
    for(int i=0; i<paths.size(); i++){  
        int a = paths[i][0], b=paths[i][1], w=paths[i][2];
        nodes[a].nearby.push_back(pair<int, int>(b, w));
        nodes[b].nearby.push_back(pair<int, int>(a, w));
    }
 
    //max_dis[i] : gates에서 해당 노드까지의 intensity 최소값
    int max_dis[50001];
    queue<int> list;   //다익스트라 진행할 큐 - 노드 번호만 저장

    //최대값으로 초기화
    for(int i=0; i<=50000; i++) max_dis[i] = INF;
    
    //모든 gates 큐에 추가(동시출발), is_gate 및 거리 수정(-1)
    for(int i=0; i<gates.size(); i++){
        list.push(gates[i]); 
        nodes[gates[i]].is_gate=true;
        max_dis[gates[i]] = -1;
    }
    
    //다익스트라 진행
    while(!list.empty()){   
        
        //target - 현재 노드번호 얻어오기
        int target = list.front(); list.pop();
        
        //인접노드 방문하며 거리값 갱신
        for(int i=0; i<nodes[target].nearby.size(); i++){  //주변 노드들에 대해
            
            //인접 노드 번호 및 가중치 얻어오기
            int nearby_num = nodes[target].nearby[i].first;
            int nearby_weight = nodes[target].nearby[i].second;
           
            //출입구인 경우 -> 방문 안하고 넘어감
            if(nodes[nearby_num].is_gate) continue; 
            
            //원래의 max_dis값 저장 - 이유 : 이 값이 갱신되지 않은 경우에는, queue에 인접노드를 추가할 필요가 없으므로
            int origin_max_dis = max_dis[nearby_num];    
            
            //인접노드의 거리값 갱신 / max_dis[target], 인접노드까지의 가중치 -> 둘중 최대값
            int new_dis = max(max_dis[target], nearby_weight); //기존 target까지의 경로 최대값, 인접노드 경로 값 비교 -> 최대값 뽑아냄
            max_dis[nearby_num] = min( max_dis[nearby_num], new_dis); //기존에 max_dis와 new_dis 중 최소값으로 갱신
              
            //값이 갱신되었고, 인접노드가 산봉우리가 아닌 경우 -> 더 진행시켜야 하므로 큐에 추가
            if( (origin_max_dis != max_dis[nearby_num] ) && nodes[nearby_num].is_summit==false){    
                list.push(nearby_num);
            }
        }
       
    }
    //거리 갱신 종료
    //max_dis[i] 값이 가장 작고 is_summit이 true인 i가 산봉우리번호, max_dis[i] 값이 최소 intensity임
    
    
    int intensity = INF;
    int summit_num = 0;
    for(int i=1; i<=n; i++){    //max_dis가장 적은거 고를거
        if(intensity > max_dis[i] && nodes[i].is_summit){
            //거리가 가장작고, 산봉우리인 것만 추려냄
            summit_num=i;
            intensity = max_dis[i];
        }
    }
    
    answer.push_back(summit_num); answer.push_back(intensity);
    
    return answer;
}
