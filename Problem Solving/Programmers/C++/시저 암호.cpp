#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i=0; i<s.length(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            int idx = s[i] - 'A';
            idx = (idx + n) % 26;
            answer += idx + 'A';
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            int idx = s[i] - 'a';
            idx = (idx + n) % 26;
            answer += idx + 'a';
        }
        else {
            answer += s[i];
        }
    }
    return answer;
}
