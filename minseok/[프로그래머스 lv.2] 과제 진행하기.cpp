#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std; 
/*
<문제>
과제는 제 시간에 시작 / 중간에 새로운 과제가 나오면 멈추고 시작
과제 끝냈을 때 멈춘 과제가 있으면 이어서 진행
  * 새로 시작해야하는 과제도 같이 있으면 새로운 과제 진행
멈춰둔 과제가 여러개인 경우, 최근에 멈춘 과제부터 시작

과제를 끝낸 순서대로 이름을 배열에 담아 return

plans 길이 <=1000
name 길이 <=10 (중복 없음)
start - hh:mm (시간)
playtime <=100(단위 : 분)

<풀이>
1. 시간순서대로 정렬 - 이후 시간을 분으로 환산해서 계산하기로 함

struct Task{
    string name;    //과제 이름
    int remain; //남은 시간
};
과제 수행 - 목록이 빌 때 까지
 - 과제 수행시간 중간에 새로운 과제 등장 시, 해당 과제 stack에 push 후 과제 시작
 - 과제 종료시간 중간에 과제 없으면 해당 과제 끝낸 것으로 판정
   - 끝낼 때 처리 : 해당 과제이름 answer에 추가, stack 안비었으면 하나 꺼내와서 진행
 stack 비어있으면 다음 시간 과제 진행
-> 반복
*/

struct Task {
    string name;    //과제 이름
    int start_time; //시작 시간
    int remain; //남은 시간
};

bool cmpp(vector<string> a, vector<string> b) {  //시간 기준 오름차순 정렬
    istringstream A(a[1]), B(b[1]);
    string h_a, h_b, m_a, m_b;
    getline(A, h_a, ':'); getline(A, m_a, '\n');
    getline(B, h_b, ':'); getline(B, m_b, '\n');

    return stoi(h_a) * 60 + stoi(m_a) < stoi(h_b) * 60 + stoi(m_b);
}

int getStartTime(vector<string> plan) {  //시간값을 분으로 환산해서 얻기
    istringstream A(plan[1]);
    string h, m;
    getline(A, h, ':'); getline(A, m, '\n');
    return stoi(h) * 60 + stoi(m);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmpp); //시간 기준 오름차순 정렬

    stack<Task> Tasks;  //처리해야 할 과제들 저장

    Task* a = new Task;
    a->name = plans[0][0]; a->start_time = getStartTime(plans[0]);  a->remain = stoi(plans[0][2]);
    //이름, 시작시간, 남은시간 저장
    int cur_time = a->start_time;   //현재 시간

    Tasks.push(*a);
    plans.erase(plans.begin());
    //초기값 스택에 넣기 완료(+과제목록에서 제거)

    while (!Tasks.empty() || !plans.empty()) {  //둘 다 비어있으면 끝


        if (plans.empty()) {  //과제목록이 빔 -> 스택에 있는게 전부
            while (!Tasks.empty()) {  //스택에 있는 모든것들을 answer에 넣고 종료
                answer.push_back(Tasks.top().name);
                Tasks.pop();
            }
            return answer;
        }

        //tmp : 현재 진행할 과제, plans[0] : 새로운 과제
        Task tmp = Tasks.top(); //현재 진행할 과제 스택에서 빼오기
        Tasks.pop();
        cur_time = tmp.start_time;  //현재시간 설정
        int end_time = cur_time + tmp.remain; // 현재과제 끝나는 시간

        //tmp : 기존과제, plans[0] : 새로운 과제
        if (end_time > getStartTime(plans[0])) { //현재과제 끝나기 전에 새로운과제 시작한 경우

            int new_start_time = getStartTime(plans[0]);    //새로운 과제 시작시간
            tmp.remain = end_time - new_start_time; //남은시간 설정
            cur_time = new_start_time;  //현재시간 설정
            Tasks.push(tmp);    //과제 넣어놓고 새로운 과제 할 준비
            Task* a = new Task;
            a->name = plans[0][0]; a->start_time = getStartTime(plans[0]);  a->remain = stoi(plans[0][2]);
            Tasks.push(*a);
            plans.erase(plans.begin());
            //새로운 과제 스택에 넣고 과제목록에서 제거완료(빼서 확인할거)

        }
        else if (end_time == getStartTime(plans[0])) {  //현재과제 끝난 동시에 새로운 과제 시작

            cur_time = end_time;    //현재시간 설정
            answer.push_back(tmp.name); //정답에 추가
            Task* a = new Task;
            a->name = plans[0][0]; a->start_time = getStartTime(plans[0]);  a->remain = stoi(plans[0][2]);
            Tasks.push(*a);
            plans.erase(plans.begin());
            //과제목록에서 빼서 스택에 추가 완료
            continue;

        }
        else {   //현재시간 기준 새로운과제 진행까지 남은시간만큼 stack에서 작업을 수행해야 함 
          
            int remain_time = getStartTime(plans[0]) - cur_time;    //새로운과제 진행까지 남은 시간          

            //tmp : 기존과제, plans[0] : 새로운 과제
            while (remain_time != 0 && !plans.empty()) {    //새로운과제 시작시간이 되거나, stack에 과제가 없으면 끝

                if (remain_time <= tmp.remain) {   //기존과제 수행하다 새로운 과제 시작
                    tmp.remain -= remain_time; remain_time = 0;
                    cur_time += remain_time;
                    if(tmp.remain!=0) Tasks.push(tmp);
                    else answer.push_back(tmp.name);
                    //진행하던 과제가 안끝났으면 stack추가, 끝났으면 정답추가 완료

                    Task a; a.name = plans[0][0]; a.start_time = getStartTime(plans[0]); a.remain = stoi(plans[0][2]);
                    Tasks.push(a);
                    plans.erase(plans.begin());
                    //plans[0] 빼서 스택에 넣기 완료 -> 다음 사이클 갈 준비 / remain_time이 0이라 루프 벗어날거

                }
                else {  //기존과제 끝내고도 시간이 남은 경우 -> stack에서 다음과제 진행
                    answer.push_back(tmp.name);   //기존과제 끝
                    cur_time += tmp.remain; remain_time -= tmp.remain;  //남은시간은 무조건 0보다 큼

                    if (Tasks.empty()) { //tasks가 비어있으면 -> plans에서 하나 넣고, 해당 루프 벗어나기
                        Task a; a.name = plans[0][0]; a.start_time = getStartTime(plans[0]); a.remain = stoi(plans[0][2]);
                        Tasks.push(a);
                        plans.erase(plans.begin());    
                        break;
                    }
                    else {//stack에서 새로운과제 tmp로 지정
                        tmp = Tasks.top(); Tasks.pop();
                    }
                }

            }
        }

    }
    return answer;
}
