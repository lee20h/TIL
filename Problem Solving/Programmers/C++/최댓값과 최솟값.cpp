#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<long long> v;
    string temp;
    
    for (int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            v.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp += s[i];
    }
    v.push_back(stoi(temp));
    sort(v.begin(),v.end());
    answer = to_string(v[0]) + ' ' + to_string(v[v.size()-1]);
    return answer;
}
