#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
<문제>
1번 수포자가 찍는 방식 : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식 : 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번부터 마지막 문제까지 정답 순서 배열 answer -> 가장 많이 맞춘 사람 배열에 담아 return

시험문제 최대 <= 10000
정답은 1, 2, 3, 4, 5중 하나
여럿이 나오면, 오름차순 정렬


<풀이>
반복문 1번에 고고

2번사람 : [2, 1, 2, 3, 2, 4, 2, 5] 반복
3번사람 : [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] 반복

i번째에서
  answer[i] : 현재 순서의 정답
  1번사람체크
  2번사람체크
  3번사람 체크

1, 2, 3 비교해서 배열에 담기(최대값이 같은 사람들은 오름차순 정렬)

<시간>
O(N)

*/
vector<int> solution(vector<int> answers) {
    vector<int> answer;
  
    int one = 0, two = 0, three = 0;    //각 수포자 번호
    vector<int> seq3 = { 3,3,  1,1,  2,2,  4,4,  5,5 };
    vector<int> seq2 = { 2, 1, 2, 3, 2, 4, 2, 5 };

    for (int i = 0; i < answers.size(); i++){
        if (i % 5 + 1 == answers[i]) one++; //1번 수포자
        if (seq2[i % seq2.size()] == answers[i])two++;  //2번 수포자
        if(seq3[i % seq3.size()] == answers[i])three++; //3번 수포자
    }

    if (one >= two && one >= three) answer.push_back(1);
    if (two>= one && two >= three) answer.push_back(2);
    if (three >= two && three >= one) answer.push_back(3);
    
    return answer;
}
