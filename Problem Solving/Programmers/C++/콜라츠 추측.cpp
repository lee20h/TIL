#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num;
    while(number != 1) {
        if(answer >= 500) {
            answer = -1;
            break;
        }
        if(number&1) {
            number = number * 3 + 1; 
        } else {
            number = number / 2;
        }
        answer++;
    }
    return answer;
}
