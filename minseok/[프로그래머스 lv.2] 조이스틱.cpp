#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
<문제>
조이스틱 조작 횟수의 최소값 구하기
처음엔 A로만 이루어져 있음

<풀이>
A에서 25번 이동하면 Z

1. 위, 아래를 통해 알파벳 조정 횟수 정하기
 - easy
 
2. 좌, 우 이동방향 횟수 정하기
 1. 그냥 한 방향으로 순차적 진행(A가 없으면 이게 최적)
   - 이걸 default로 설정([0] ~ [끝] 까지 이동)
 2. A가 있는 구간에 대해 처리하면서 좌우로 왔다갔다 진행
   - 이 때 두가지 경우가 있음 -> 오른쪽 이동 후 왼쪽이동 / 왼쪽 이동 후 오른쪽 이동

<시간>
O(N) -> 가능
*/
int solution(string name) {
    int answer = 0;
    int move = name.size() - 1; //이동 횟수 디폴트 : 순차적으로

    for (int i = 0; i < name.size(); i++) {   //알파벳 이동 처리
        
        //알파벳 조정 카운트
        if (name[i] <= 'N') answer += (int)name[i] - (int)'A';
        else answer += (int)'Z' - (int)name[i] + 1;

        //좌우 이동 카운트
        int idx = i + 1;    //idx : A구간 다음 알파벳 위치
        
        while (idx < name.size() && name[idx] == 'A')   //A가 안나올 때까지 계속 오른쪽으로 idx를 이동
            idx++;
        
        //두 가지 방법 적용해서 최솟값 찾기
        // i: [0] -> [i]로 가는 이동 횟수(방향 : 오른쪽)
        // len(name) - idx: [0] -> [idx]로 가는 이동 횟수(방향 : 왼쪽)
        int left_right = (name.size() - idx) * 2 + i;  // [0] -> [i](오른쪽) -> [idx](왼쪽)
        int right_left = i * 2 + (name.size() - idx);  // [0] -> [idx](왼쪽) -> [i](오른쪽)
        move = min(move, right_left);
        move = min(move, left_right);
    }
    answer += move; //좌우이동 횟수   
    return answer;
}
