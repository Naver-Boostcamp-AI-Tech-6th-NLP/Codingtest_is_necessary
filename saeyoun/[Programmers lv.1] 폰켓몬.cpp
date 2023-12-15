#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> m;

int solution(vector<int> nums)
{
    int answer = 0;
    int halfCnt=nums.size()/2;
    int typeCnt=0;
    for(auto i=nums.begin();i!=nums.end();++i){
        if(m.count(*i)==0) typeCnt++;
        m[*i]++;
    }
    if(typeCnt>=halfCnt)answer=halfCnt;
    else answer=typeCnt;
    return answer;
}
