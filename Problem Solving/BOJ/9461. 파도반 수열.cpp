#include<iostream>
#include<cstring>
using namespace std;

long long dp[101];

long long sol(int n) {
	if(dp[n] == -1) dp[n] = sol(n-1) + sol(n-5);
	return dp[n];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	int test;
	cin >> test;
	for (int t=0; t<test; t++) {
		int n;
		cin >> n;
		cout << sol(n) << '\n';
	}
	
}
