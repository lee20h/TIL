#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    char prev;
    for (int i=0; i<words.size(); i++) {
        if(m[words[i]]) {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
        if(prev != words[i][0] && i != 0) {
        	answer.push_back(i%n+1);
        	answer.push_back(i/n+1);
        	break;
		}
        m[words[i]]++;
        prev = words[i][words[i].length()-1];
    }
    if(answer.empty()) {
    	answer.push_back(0);
    	answer.push_back(0);
	}
    return answer;
}
