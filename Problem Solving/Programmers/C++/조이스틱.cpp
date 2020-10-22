#include <string>
 
using namespace std;
 
int solution(string name) {
    int answer = 0, idx = 0;
    string temp(name.length(), 'A');
    while (1) {
        temp[idx] = name[idx];
        if(name[idx]-'A' > 'Z'+1-name[idx])
        	answer += 'Z'+1-name[idx];
        else
        	answer += name[idx]-'A';
        if (temp == name)    
			break;
        for (int move = 1; move < name.length(); move++) {
            if (name[(idx + move) % name.length()] != temp[(idx + move) % name.length()]) {
                idx = (idx + move) % name.length();
                answer += move;
                break;
            }
            else if (name[(idx + name.length() - move) % name.length()] 
                != temp[(idx + name.length() - move) % name.length()]) {
                idx = (idx + name.length() - move) % name.length();
                answer += move;
                break;
            }
        }
    }
    return answer;
}
