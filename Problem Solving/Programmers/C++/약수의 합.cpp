#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i=1; i< sqrt(n); i++) {
        if(n%i == 0) {
            answer += i;
            answer += n / i;
        }
    }
    int a = sqrt(n);
    double b = sqrt(n);
    if (a == b)
        answer += a;
    return answer;
}
