#include <string>
#include <vector>
#include <sstream>

using namespace std;
/*
<문제>
로봇강아지가 산책함 - O가 지나다니는 길, X가 장애물
"E 5" 형태로 주어짐(동쪽으로 5칸)
공원을 벗어나거나, 장애물을 만나면 해당 명령 무시
가로 W, 세로 H일 때 좌측상단 (0, 0), 우측하단 (H-1, W-1)
모든 명령 수행 후 놓인 위치를 (세로좌표, 가로좌표) 순으로 배열에 담아 return

park길이 <=50
park[i]길이 <=50

*/
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int x, y;   //현재 좌표(세로, 가로)
    for (int i = 0; i < park.size(); i++) {
        bool flag = false;
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S') {
                flag = true;
                x = i; y = j; break;
            }
            if (flag)break;
        }
    }
    //현재좌표 x, y(세로, 가로) 저장완료

    for (int i = 0; i < routes.size(); i++) { //경로 리스트 순회
        stringstream ss(routes[i]);
        string way, tmp; int distance;
        getline(ss, way, ' '); getline(ss, tmp, '\n'); distance = stoi(tmp);
        //방향, 거리 저장 완료
        int garo = park[0].size(), sero = park.size();  //가로세로 길이

        if (way.compare("E") == 0) {    //동
            if ((y + distance) >= garo) continue; //벽 거르기
            bool flag = true; //명령수행가능여부

            for (int j = 1; j <= distance; j++) {  //해당 방향 나아가며 장애물 확인
                if (park[x][y + j] == 'X') {
                    flag = false;
                    break;
                }
            }

            if (flag) {   //이동가능할 때
                y += distance;
            }

        }
        else if (way.compare("W") == 0) {   //서

            if ((y - distance) < 0) continue; //벽 거르기
            bool flag = true; //명령수행가능여부

            for (int j = 1; j <= distance; j++) {  //해당 방향 나아가며 장애물 확인
                if (park[x][y - j] == 'X') {
                    flag = false;
                    break;
                }
            }

            if (flag) {   //이동가능할 때
                y -= distance;
            }

        }
        else if (way.compare("S") == 0) {   //남
            if ((x + distance) >= sero) continue; //벽 거르기
            bool flag = true; //명령수행가능여부

            for (int j = 1; j <= distance; j++) {  //해당 방향 나아가며 장애물 확인
                if (park[x + j][y] == 'X') {
                    flag = false;
                    break;
                }
            }

            if (flag) {   //이동가능할 때
                x += distance;
            }
        }
        else if (way.compare("N") == 0) {   //북
            if ((x - distance) < 0) continue; //벽 거르기
            bool flag = true; //명령수행가능여부

            for (int j = 1; j <= distance; j++) {  //해당 방향 나아가며 장애물 확인
                if (park[x - j][y] == 'X') {
                    flag = false;
                    break;
                }
            }

            if (flag) {   //이동가능할 때
                x -= distance;
            }
        }

    }
    answer.push_back(x); answer.push_back(y);
    return answer;
}
