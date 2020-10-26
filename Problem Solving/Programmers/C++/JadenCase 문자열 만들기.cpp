#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for (int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            flag = true;
            answer += " ";
            continue;
        }
        if(flag) {
            answer += toupper(s[i]);
            flag = false;
        }
        else {
            answer += tolower(s[i]);
        }
    }
    return answer;
}
