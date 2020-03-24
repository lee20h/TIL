#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[41];
int one, zero;
int fibonacci(int n) {
	if(dp[n] != -1) {
		if(n<2) return dp[n];
		else return dp[n];
	}
	else return dp[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testcase;
	cin >> testcase;
	memset(dp,-1,sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	int n;
	for (int i=0; i<testcase; i++) {
		cin >> n;
		one = zero = 0;
		if(n==0) {
			cout << "1 0" << '\n';
			continue;
		}
		else if (n==1) {
			cout << "0 1" << '\n';
			continue;
		}
		fibonacci(n);
		cout << dp[n-2] << ' ' << dp[n-1] << '\n';
	}
}
