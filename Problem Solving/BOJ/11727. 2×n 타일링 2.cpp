#include <iostream>
#include <cstring>
using namespace std;

unsigned long long dp[1001];
int n;

unsigned long long sol(int m) {
	if(dp[m] == -1) {
		if(m % 2 !=0) {
			dp[m] = (sol(m-2) * 4 + 1) % 10007;
		}
		else {
			dp[m] = (sol(m-2) * 4 - 1) % 10007; 
		}
	}
	return dp[m];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	dp[1] = 1;
	dp[2] = 3;
	cin >> n;
	sol(n);
	cout << dp[n];
}
