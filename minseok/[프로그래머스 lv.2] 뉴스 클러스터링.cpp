#include <string>
#include <map>
#include <iostream>
using namespace std;
/*

<문제>

블라인드 전형 주목 기사
코테 주목 기사
각각 묶어서 보여주고자 함

자카드 유사도

두 집합 A, B 사이의 자카드 유사도 J(A, B) = 두 집합의 교집합 크기 / 두 집합의 합집합 크기
나눗셈이 정의되지 않으면 1로 정의

중복을 허용하는 다중 집합에 대해 확장 가능

문자열 끊어서 유사도 계산
FRANCE, FRENCH -> 두 글자씩 끊어서 만들기


입력 : str1, str2

두 글자씩 끊어서 다중 집합의 원소로
영문자 글자 쌍만 유효, 공백이나 숫자/특수문자가 들어있으면 그 글자 쌍 버림

다중집합 원소 사이 비교 시, 대소문자 차이 무시

출력 : 두 문자열의 자카드 유사도 출력 -> 65536 곱한 후, 소수점 아래를 버리고 정수부만 출력

각 입력 길이 <= 1000



<풀이>

두 문자열이 들어왔을 때 먼저 각 조합들 집합 구하기
거기서 교집합 합집합 구하려면? -> 겹치는 개수

map 쓰면 될 것 같은데?

두 문자열의 각 두 글자씩 따서 맵에 저장 -> O(1000) / value에 +1 하기

map 각 원소들 다 보면서 비교하면 될 것 같은데? -> O(100만)

교집합 : O(100만)
합집합 : O(100만)

가능할 듯?

1. str1, str2 -> map에 각 두글자씩 따서 저장
    1-1. 특수문자, 공백 등 필요없는 것들은 제거
2. map 원소 보면서, map2에 있으면 교집합 처리
3. 교집합 개수를 계산 -> 합집합은 자동으로 계산됨


<시간>
map 삽입/탐색 -> O(logn)
*/
int solution(string str1, string str2) {
    int answer = 0;

    if(str1.size()==0 && str2.size()==0) return 65536;  //기저사례
    
    map<string, int> map1;
    map<string, int> map2;
    
    //대소문자 처리
    for(int i=0; i<str1.size(); i++){
        if(str1[i] >= 'A' && str1[i] <= 'Z'){
            str1[i]+=32;
        }
    }
    for(int i=0; i<str2.size(); i++){
        if(str2[i] >= 'A' && str2[i] <= 'Z'){
            str2[i]+=32;
        }
    }
    
    //map, map2 초기화
    for(int i=0; i<str1.size()-1; i++) {
        //필요없는 것들은 넘기기 - 소문자 아니면 넘기면 됨
        if(str1[i] < 'a' || str1[i] > 'z') continue;
        if(str1[i+1] < 'a' || str1[i+1] > 'z') continue;
            
            
        string target = str1.substr(i, 2);

        if (map1.find(target) != map1.end())  //target 존재
            map1[target]+=1;
        else                        //target 없음
            map1[target]=1; 
    }
    
    //map, map2 초기화
    for(int i=0; i<str2.size()-1; i++) {
    
        //필요없는 것들은 넘기기 - 소문자 아니면 넘기면 됨
        if(str2[i] < 'a' || str2[i] > 'z') continue; 
        if(str2[i+1] < 'a' || str2[i+1] > 'z') continue;    
       
        string target = str2.substr(i, 2);

        if (map2.find(target) != map2.end())  //target 존재
            map2[target]+=1;
        else                        //target 없음
            map2[target]=1; 
    }
    
    if(map1.size()==0 && map2.size()==0) return 65536;  //기저사례
    
    int gyo=0;   //교집합 개수
    
    map<string, int>::iterator iter;
    for(iter=map1.begin(); iter!=map1.end(); iter++){ //map 요소 반복
        string key = iter->first; int value = iter->second;
        
        if(map2.find(key)!=map2.end()){ //찾는 값이 map2에 있음 -> 교집합
            int a = value, b = map2.find(key)->second;  //value값 비교해서 교집합 처리
            if(a>=b)
                gyo+=b;
            else
                gyo+=a; 
        } 
    }

    int hap = 0;    //map1, map2 원소 개수 모두 구하기
    for(map<string, int>::iterator iter=map1.begin(); iter!=map1.end(); iter++)
        hap+=iter->second;
    for(map<string, int>::iterator iter=map2.begin(); iter!=map2.end(); iter++)
        hap+=iter->second;
    hap-=gyo;
    
    answer = (double)gyo / hap * 65536;
    cout<<gyo<<endl;
    cout<<map1.size()<<endl;
    cout<<map2.size()<<endl;
    
    return answer;
}
