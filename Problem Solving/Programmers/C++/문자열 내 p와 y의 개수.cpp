#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    for (int i=0; i<s.length(); i++) {
        s[i] = tolower(s[i]);
        if(s[i] == 'p')
            p++;
        else if(s[i] == 'y')
            y++;
    }
    p == y ? answer = true : answer = false;
    return answer;
}
