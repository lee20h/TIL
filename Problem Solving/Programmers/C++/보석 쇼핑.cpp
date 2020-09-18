#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int left = 0, right = 0;
    set<string> s;
    map<string, int> m;
    for (int i=0; i<gems.size(); i++) {
        s.insert(gems[i]);
    }
    answer.push_back(0);
    answer.push_back(gems.size()-1);
    m[gems[0]]++;
    while(left<=right) {
        if(m.size() == s.size()) {
        	if(answer[1] - answer[0] > right - left) {
        		answer[1] = right;
        		answer[0] = left;
			}
            m[gems[left]]--;
            if(m[gems[left]] == 0)
                m.erase(gems[left]);
            left++;
		}
        else {
            if(right + 1 >= gems.size()) break;
            else{
                m[gems[++right]]++;
            }
        }
    }
    answer[0]++;
    answer[1]++;
    return answer;
}
