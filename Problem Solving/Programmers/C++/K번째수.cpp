#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int t=0; t<commands.size(); t++) {
        vector<int> temp;
        int q,w,e;
        q = commands[t][0]-1;
        w = commands[t][1]-1;
        e = commands[t][2]-1;
        
        for (int i=q; i<=w; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[e]);
    }
    return answer;
}
