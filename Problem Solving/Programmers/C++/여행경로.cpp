#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e5+1;

bool visited[MAX];
string ans = "abc";

void dfs(vector<vector<string>> &tickets, string from, string path, int level) {
    if(level == tickets.size()) {
        if(path < ans)
        	ans = path;
        return;
    }
    
    for (int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == from && !visited[i]) {
            visited[i] = true;
            dfs(tickets, tickets[i][1], path + tickets[i][1], level+1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    string start = "ICN";
    sort(tickets.begin(), tickets.end());
    
    dfs(tickets, start, start, 0);
    
    for(int i=0; i<ans.length(); i+=3) {
        answer.push_back(ans.substr(i,3));
    }
    return answer;
}
