#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.length();
    if(len < 4 || len > 6 || len == 5)
        answer = false;
    else {
        for (int i=0; i<len; i++) {
            if(!('0' <= s[i] && s[i] <= '9'))
                answer = false;
        }
    }
    return answer;
}
