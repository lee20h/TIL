#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n) {
        int num = n % 3;
        if(num == 1)
            answer = to_string(num) + answer;
        else if (num == 2)
            answer = to_string(num) + answer;
        else if(num == 0) {
            answer = "4" + answer;
            n--;
        }
        n /= 3;
    }
    return answer;
}
