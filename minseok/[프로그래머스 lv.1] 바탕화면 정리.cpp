#include <string>
#include <vector>

using namespace std;
/*
<문제>
바탕화면 wallpaper 배열 -> (0, 0) / 빈칸은 ., 파일이 있는 칸은 #을 가짐
최소한의 드래그 거리로 바탕화면에 있는 모든 파일을 지우고자 함
이동거리가 최소인 드래그 시작점, 끝점을 담은 정수배열을 return
 
wallpaper길이 <= 50
wallpaper[i]길이 <=50
시작점 : 좌측상단, 끝점 : 우측하단 을 만족해야함
 
<풀이>
가장 좌측상단 좌표 담고, 그 후 가장 우측하단 좌표에 각 1씩 더한 값 담기
*/

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_i =100, min_j=100, max_i=-1, max_j=-1; 
    for(int i=0; i<wallpaper.size(); i++){  //세로
        for(int j=0; j<wallpaper[i].size(); j++){   //가로
                     
            if(wallpaper[i][j]=='#'){   //파일인 경우
                if(i<min_i)  min_i=i;
                if(j<min_j)  min_j=j;;
                if(i>max_i)  max_i=i;
                if(j>max_j)  max_j=j;
       
            }
        }
       
    }
    //for문 다 돌고, answer 구하기
    answer.push_back(min_i);
    answer.push_back(min_j);
    answer.push_back(max_i+1);
    answer.push_back(max_j+1);
    return answer;
}