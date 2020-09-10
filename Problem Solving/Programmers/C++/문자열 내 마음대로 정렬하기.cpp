#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end());
    
    vector<pair<char,int>> c;
    for (int i=0; i<strings.size(); i++) {
        c.push_back({strings[i][n], i});
    }
    sort(c.begin(),c.end());
    
    for (int i=0; i<strings.size(); i++) {
        answer.push_back(strings[c[i].second]);
    }
    return answer;
}
