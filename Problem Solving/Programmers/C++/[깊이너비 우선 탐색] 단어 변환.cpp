#include <string>
#include <vector>
#include <algorithm>

const int MAX = 50;
using namespace std;

int ans = 2 * MAX;

void dfs(string begin, string target, vector<string> words, int cnt, bool * visited) {
    for (int i=0; i<words.size(); i++) {
    	int diff = 0;
        for (int j=0; j<begin.size(); j++) {
            if(begin[j] != words[i][j]) diff++;
        }
        if(diff > 1) continue;
        
        if(words[i] == target) {
            ans = min(ans,cnt+1);
            return;
        }
        
        if(visited[i]) continue;
        
        visited[i] = true;
        dfs(words[i], target, words, cnt+1, visited);
    }
}

int solution(string begin, string target, vector<string> words) {
	bool visited[MAX] = {false,};
	dfs(begin, target, words, 0, visited);
    if(ans == 2 * MAX) return 0;
    else return ans;
}
