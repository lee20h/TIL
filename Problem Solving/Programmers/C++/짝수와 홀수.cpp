#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if(num & 1)
        answer = "Odd";
    else
        answer = "Even";
    return answer;
}
