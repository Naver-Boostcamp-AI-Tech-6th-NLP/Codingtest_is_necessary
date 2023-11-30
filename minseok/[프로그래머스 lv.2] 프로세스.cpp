#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cur_location = location;    //현재 위치

    while (true) {
        for (int i = 0; i < cur_location; i++) {    //location까지 진행

            bool flag = true;  //인쇄 할지 말지 여부

            for (int i = 0; i < priorities.size(); i++) {
                if (priorities[0] < priorities[i]) {    //뒤로 보냄
                    priorities.push_back(priorities[0]);
                    flag = false;
                    break;
                }
            }

            priorities.erase(priorities.begin());
            if (flag) answer += 1;       //인쇄

        }

        //이후 해당 위치에서 인쇄 할 지 말지를 진행
        bool flag = true;


        for (int i = 0; i < priorities.size(); i++) {
            if (priorities[0] < priorities[i]) {    //뒤로 보냄
                priorities.push_back(priorities[0]);
                flag = false;
                cur_location = priorities.size() - 2;
                break;
            }
        }
        priorities.erase(priorities.begin());

        if (flag) { //답 찾음
            answer += 1;
            return answer;
        }

    }
    
    
}
