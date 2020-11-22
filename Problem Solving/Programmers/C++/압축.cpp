#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    int cnt = 1;
    for (int i=0; i<26; i++) {
        string temp;
        char c = 'A' + i;
        temp += c;
        m[temp] = cnt++;
    }
    
    for (int i=0; i<msg.length(); i++) {
        string str;
        str += msg[i];
        int idx = i;
        while(m.find(str) != m.end()) {
            str += msg[++idx];
        }
        i += idx - i - 1;
        m[str] = cnt++;
        str.pop_back();
        answer.push_back(m[str]);
    }
    return answer;
}
