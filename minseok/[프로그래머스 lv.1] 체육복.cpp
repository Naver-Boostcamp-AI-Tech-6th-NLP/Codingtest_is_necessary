#include <string>
#include <vector>

using namespace std;
/*
<문제>
체육복 - 바로 앞이나 뒷번호 학생에게만 빌려줄 수 있음
전체 학생 수, 도난당한학생 배열, 여벌가져온학생 배열 
-> 체육수업 들을 수 있는 학생 최댓값

학생 수 30 이하
도난, 여벌 학생 -> n이하 / 중복없음

여벌이면서 도난일 수 있음 -> 다른학생 체육복 대여 불가

<풀이>
lost -> 모두 뒤져보며 reserve인지 확인 -> 상쇄작업
lost 양쪽 중 한쪽만 reserve인 것들 먼저 처리
나머지 처리

*/
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n, 0); //0 : 평범, -1 : 도난, 1 : 여벌
    for(int i=0; i<lost.size(); i++)
        student[lost[i]-1]-=1;
    for(int i=0; i<reserve.size(); i++)
        student[reserve[i]-1]+=1;
    //도난여벌 상쇄완료
    
    for(int i=0; i<student.size(); i++){ //한쪽만 여벌인 lost 처리
        if(student[i]==-1){
            
            if(i==0 && student[i+1]==1){    //0인경우 오른쪽만 보기
                student[i+1]--; student[i]++;
            }
            else if(i==student.size()-1 && student[i-1]==1){   //끝인경우 왼쪽만 보기
                 student[i-1]--; student[i]++;      
            }
        
            if( (i!=0 && student[i-1]==1) && (i!=student.size()-1 && student[i+1]!=1) ){ //왼쪽만
                student[i-1]--; student[i]++;
            }
            else if( (i!=0 && student[i-1]!=1) && (i!=student.size()-1 && student[i+1]==1) ){ //오른쪽만
                student[i+1]--; student[i]++;
            }
        }
        
    }
    //한쪽만 받아야 하는 경우 처리 완료
    
     for(int i=0; i<student.size(); i++){ //나머지 처리
        if(student[i]==-1){
            if( i!=0 && student[i-1]==1 ){ //왼쪽인 경우
                student[i-1]--; student[i]++;
            }
            else if(i!=student.size()-1 && student[i+1]==1 ){ //오른쪽인 경우
                student[i+1]--; student[i]++;
            }
        }
    }
    //나머지 처리 완료

    for(int i=0; i<student.size(); i++)
        if(student[i]>=0) answer++;
 
    return answer;
}