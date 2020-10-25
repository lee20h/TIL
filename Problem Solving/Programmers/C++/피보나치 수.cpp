#include <string>
#include <vector>
using namespace std;

const int MAX = 1e5+1;
int dp[MAX];

int fibo(int n) {
    if(dp[n])
        return dp[n];
    return dp[n] = (fibo(n-1) + fibo(n-2)) % 1234567;
}

int solution(int n) {
    int answer = 0;
    dp[2] = dp[1] = 1;
    return answer = fibo(n);
}
