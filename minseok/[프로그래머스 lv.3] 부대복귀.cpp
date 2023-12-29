#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
<문제>
각 지역은 유일한 번호로 구분, 강철부대원이 여러 지역에 흩어져 임무수행
두 지역간 길 통과하는데 걸리는 시간은 모두 1
각 부대원은 지도 정보를 이용하여 최단시간에 부대 복귀하고자 함
적군의 방해로 시작때와 다르게 돌아오는 경로가 없어져 복귀 불가능한 부대원 존재

총지역 수 n, 길 정보를 담은 2차원정수배열 roads, 부대원 위치한 서로다른 정수배열 sources, 강철부대 지역 destination
-> sources의 원소 순서대로 강철부대로 복귀할 수 있는 최단시간을 담은 배열 return(복귀 불가능하면 -1)

n<=10만, 각 지역은 1~n까지 번호로 구분됨
roads 길이 <= 50만 / roads 원소 길이 = 2 / [a, b] 형태로, a, b가 서로 왕복할 수 있음을 의미 / 동일정보 x
sources 길이 <= 500
destination <= n

<풀이>
BFS - 다익스트라, 벨만포드 등 생각나서 벨만포드 썼다가 시간초과
 ->결국 목적지에서부터 BFS로 하나하나 찾아나가면 되는거였음

<시간>
O(nlogn)
*/
struct Vertex{
    int num;
    bool visited;
    vector<int> nearby; //인접 정점 
    int depth;  //현재 BFS 깊이
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    int start = destination;  //시작지점(도착지점에서부터 뻗어나가므로 시작지점이 됨)
    
    vector< pair<pair<int, int>, int> > edges;   
    //정점 - <from, to>, weight 순으로 설정 / 이 형태 좋은거 같아서 학습목적으로 남겨둠
    
    for(int i=0; i<roads.size(); i++){ //간선 반복
          int from = roads[i][0];
          int to = roads[i][1];
          int weight = 1;   //무조건 1이지만, 학습목적으로 남겨둠
          pair<int, int> a; a.first=from; a.second=to;
          pair<pair<int, int>, int> b; b.first=a; b.second=weight;
          edges.push_back(b);
    }
    //edges 설정완료
    
    Vertex vertex[100001];  for(int i=0; i<=100000; i++) vertex[i].num=i; //정점들
    int answers[100001]; for(int i=0; i<=100000; i++) answers[i]=-1;   //목적지로부터 각 정점의 거리 / -1로 초기화 
    
    for(int i=0; i<edges.size(); i++){  //인접정점 설정
        int from = edges[i].first.first;
        int to = edges[i].first.second;        
        vertex[from].nearby.push_back(to);
        vertex[to].nearby.push_back(from);
    }
    
    answers[start]=0;   //시작정점 거리 0 설정
    vertex[start].depth=0; vertex[start].visited=true; //시작정점 depth, visited설정
    
    queue<Vertex> list;    //BFS 수행할 리스트
    list.push(vertex[start]);   //시작 정점 push
    
    while(!list.empty()){   //BFS 수행
        Vertex cur_vertex = list.front(); list.pop();   //현재 vertex
       
        for(int i=0; i<cur_vertex.nearby.size(); i++){  //인접 노드들 방문
            int target = cur_vertex.nearby[i];  //queue에 추가할 정점번호
            if(vertex[target].visited==true) continue;
            vertex[target].visited = true; vertex[target].depth = cur_vertex.depth+1;  //visited, depth설정
            list.push(vertex[target]);  //list 추가
            answers[target]=cur_vertex.depth+1;
        }  
    }
    
    for(int i=0; i<sources.size(); i++) //정답 집어넣기
        answer.push_back(answers[sources[i]]);

    return answer;
}
