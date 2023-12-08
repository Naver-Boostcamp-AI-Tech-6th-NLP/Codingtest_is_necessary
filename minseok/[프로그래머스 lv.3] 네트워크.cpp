#include <string>
#include <vector>
#include<queue>
using namespace std;

class Node {
public:
	int num;
	bool searched = false;
	vector<Node*> connected;

	Node(int n) {
		num = n;
	}
};


class Graph {
public:
	vector<Node> nodelist;

	Graph(int n) {
		for (int i = 0; i < n; i++) {
			Node nod(i);
			nodelist.push_back(nod);
		}
	}
	
	int Search(Node start) {	//그래프 탐색
		
		if (start.searched == true) return -1;
		
		queue<Node*> list;

		list.push(&start);
		start.searched = true;

		while (!list.empty()) {	//빌 때까지 빼고 주변것들 다 큐에 추가하고 반복
			Node* target = list.front();
			list.pop();
			
			for (int i = 0; i < target->connected.size(); i++) {	//target의 연결된 노드들 탐색
				if (target->connected[i]->searched == false) {
					target->connected[i]->searched = true;
					list.push(target->connected[i]);
				}
			}
		}


		return 0;

	}

};


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	
	Graph g(n);
	
	for (int i = 0; i < computers.size(); i++) {
		for (int j = i; j < computers[i].size(); j++) {
			if (computers[i][j] == 1) {	//i와 j가 연결
				g.nodelist[i].connected.push_back(&g.nodelist[j]);
				g.nodelist[j].connected.push_back(&g.nodelist[i]);
			}
		}
	}
	//g에 그래프 연결정보 설정완료

	
	for (int i = 0; i < g.nodelist.size(); i++) {
		if (g.Search(g.nodelist[i]) == 0)
			answer++;
	}
	

	return answer;
}
