#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    answer = long long(a+b) * long long(abs(a-b)+1)/2;
    return answer;
}
