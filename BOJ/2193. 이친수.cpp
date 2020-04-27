#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long dp[90];
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i=2; i<90; i++) {
		dp[i] = dp[i-2] + dp[i-1];
	}
	cout << dp[n-1];
}
