#include <vector>
#include <algorithm>
using namespace std;
/*
<문제>
N마리 폰켓몬 중, N/2마리를 선택하는데, 최대한 많은 종류의 폰켓몬을 선택하는 경우의 종류 수 return


nums : 폰켓몬 종류 담긴 1차원배열
nums길이 <= 1만 / 항상 짝수
폰켓몬 종류 번호 <= 20만
여러가지 경우가 있어도 최댓값만 return


<풀이>
일단 N/2가 목표
최대한 많은 종류 -> 일단 정렬
정렬하면 순서대로 나오자너 -> 그 후 중복 제거 후 N/2랑 비교해서 리턴하면 될듯


<시간>
정렬 : nlogn
반복 1번 돎 -> 20만
*/
int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    
    int cur_num = nums[0];    //현재 번호
    vector<int> list; list.push_back(nums[0]);   //번호 목록에 초기값 넣기
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == cur_num) continue;
        list.push_back(nums[i]); cur_num = nums[i];
    }
    
    int target = list.size();
    if(target > nums.size()/2) answer = nums.size()/2;
    else answer = target;
    
    return answer;
}
