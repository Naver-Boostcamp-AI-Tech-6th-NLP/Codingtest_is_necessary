#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int ii=0; ii<commands.size(); ii++){
        int i=commands[ii][0], j=commands[ii][1], k=commands[ii][2];
        
        vector<int> list;
        for(int a=i-1; a<=j-1; a++){
            list.push_back(array[a]);
        }
        
        sort(list.begin(), list.end());
        
        answer.push_back(list[k-1]);
    }
    
    return answer;
}
