#include <string>
#include <vector>

using namespace std;
/*
<문제>
카펫 - 중앙엔 노란색, 테두리 1줄은 갈색
갈색 / 노란색 격자수가 주어졌을 때, 카펫의 가로 세로 크기를 순서대로 담아 return

brown <= 5000
yellow <= 200만
카펫의 가로길이 >= 세로길이

<풀이>

yellow 가 (가로 - 2)랑 나누어 떨어짐
그리고, yellow로부터 구한 세로 줄 수는 yellow / (가로 - 2) + 2 임 -> 몫이 세로 줄 수 -2이므로 2를 더해줌
마지막으로, brown은 2*가로 + 2*세로 -4임 -> 이걸 yellow랑 가로로 표현하면
 -> brown = 2*가로 + 2*(yellow/(가로-2) + 2) -4
          = 2*가로 + 2*yellow/(가로-2)
 -> 좀 편하게, 
    brown/2 = 가로 + yellow/(가로-2)
가로를 i로 두고 반복문 돌리기
 
정리하면,
1~yellow중 하나인 i에 대해
    가로 = i+2
    세로 = yellow / i + 2
    brown/2 = (i+2) + yellow/i
를 만족하는 i의 최댓값 구하기!

그러면,
i를 차례대로 보면서(yellow~1까지)
    yellow가 i로 나누어 떨어지면,
        여기서 brown/2을 보고 갯수를 맞춰보면 됨
        i+2를 가로로 설정
        이에 따른 세로 구하고, brown과 비교
        맞으면 값 집어넣고 return

<시간>
O(yellow)  - 200만
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    brown /= 2;    //미리 나눠놓기

    //가로가 세로보다 크거나 같으므로, 가로 크기를 yellow부터 1까지 역순으로 봄
    for (int i = yellow; i >=1; i--) {
        if (yellow% i == 0 && i + yellow / i + 2 == brown) {    //brown/2 : i+2 + yellow/i (비교해보는거)
                answer.push_back(i+2);          //가로 : i+2(가로는 최소 3)
                answer.push_back(yellow/i+2);   //세로 : yellow/i + 2,     
            break;
        }
    }
    return answer;
}

/*
<의식의 흐름>

brown, yellow를 식으로 표현하면 될 것 같음

(가로 + 세로) * 2 - 4 = brown
가로*세로 - brown = yellow 
이걸 만족하는 가로, 세로 찾으면 됨

2가로 + 2세로 = brown + 4
가로세로 = brown + yellow
-16가로 -16세로 = -8brown - 32
4가로^2 + 4세로^2 = brown^2 + 16 - 8yellow
세로 = (brown + 4) / 2 - 가로
가로^2 + 세로^2 = (brown^2 + 16 - 8yellow) / 4
가로^2 + 가로^2 -가로*(brown+4) + (brown+4)^2/4 = brown^2/4 + 4 -2yellow

제곱은 좀 아닌것 같고..(너무 복잡해짐 -> 이게 아님)
가로, 세로를 표현해보자

가로 = yellow/(세로-2)
세로 = yellow/(가로-2)

yellow는 (가로-2), (세로-2) 랑 나누어 떨어져야 함
 -> 가로를 i로 두고 반복문 돌려버리면 될 것 같음
이에 따른 brown은 (가로 + 세로) * 2 - 4이므로, 대입해서 비교해보고 맞으면, 정답임
될 것 같음!
*/
