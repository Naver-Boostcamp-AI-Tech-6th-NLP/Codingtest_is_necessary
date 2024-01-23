#include <string>
#include <vector>

using namespace std;
/*
<문제>
새로운 유저가 아이디 규칙에 맞지 않는 아이디 입력 시, 유사하면서 규칙에 맞는 아이디를 추천해주기

길이는 3~15자
소문자, 숫자, -, _, . 만 사용 가능
마침표는 처음과 끝에 x, 연속으로도 x

1. 대문자를 소문자로 치환
2. 예외문자 제거
3. 마침표 연속부분 하나로 치환
4. 처음/끝 마침표 제거
5. 빈 문자열이면, "a" 대입
6. 16자 이상이면, 첫 15문자까지만 / 제거 후 마침표가 끝에 위치하면, 해당 마침표 제거
7. 길이 2자 이하면, 마지막 문자를 길이가 3 될 때까지 반복해서 붙이기

new_id길이 1000 이하
new_id는 대문자, 소문자, 숫자, 특수문자로 구성
특수문자 한정 : -_.~!@#$%^&*()=+[{]}:?,<>/

<풀이>
전~부 구현

1010~

<시간>
*/
#include<iostream>
string solution(string new_id) {
    string answer = "";
    
    //1단계
    for(int i=0; i<new_id.size(); i++){
        char target = new_id[i];
        if(target >= 'A' && target <='Z')
            new_id[i] += 32; //소문자로 변경
    }
    
    //2단계
    for(int i=0; i<new_id.size(); i++){
        char target = new_id[i];
        if(target >= 'a' && target <='z') continue; //소문자
        if(target >= '0' && target <= '9') continue;    //숫자
        if(target == '-' || target=='_' || target=='.') continue; //예외문자
        
        new_id.erase(new_id.begin()+i); i--;  //여기까지 온 경우 -> 제거
    }
    
    //3단계
    for(int i=0; i<new_id.size()-1; i++){
        if(new_id.size()<2) break;
        
        char t = new_id[i];
        char t_1 = new_id[i+1];
        if(t=='.' && t_1=='.'){ //연속 마침표 두 개인 경우 -> 하나를 지움
            new_id.erase(new_id.begin()+i+1); i--;  // 제거
        }
    }
   
    //4단계
    bool flag = true;
    while(flag) {
        
        flag=false;
        
        if(new_id.size()>0 && new_id[0]=='.') 
        { new_id.erase(new_id.begin()); flag=true; }
        
        if(new_id.size()>0 && new_id[new_id.size()-1]=='.') 
        { new_id.pop_back(); flag=true; }
         
    }
    
    
    //5단계
    if(new_id.size()==0) new_id="a";
    
    //6단계
    if(new_id.size()>=16){
        new_id = new_id.substr(0, 15);  //15자만 떼오기
        if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.end()-1);  //뒤에 마침표면 제거
    }
    
    //7단계
    if(new_id.size()<=2){
        while(new_id.size()<3){
            new_id+=new_id[new_id.size()-1];    //길이 3 될 때 까지 마지막문자 추가
        }
    }
    
    
   
    answer = new_id;
    return answer;
}
