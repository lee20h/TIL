#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int a = sqrt(n);
    double b = sqrt(n);
    if(a == b)
        answer = pow(a+1,2);
    else 
        answer = -1;
    return answer;
}
