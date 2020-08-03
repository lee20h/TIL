#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	int n;
	for (int t=0; t<test; t++) {
		cin >> n;
		int v[2][100001];
		int dp[2][100001];
		for (int i=0; i<2; i++) {
			for (int j=1; j<=n; j++) {
				cin >> v[i][j];
			}
		}
		dp[1][0] = dp[0][0] = 0;
		dp[0][1] = v[0][1];
		dp[1][1] = v[1][1];
		for (int i=2; i<=n; i++) {
			dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + v[0][i];
			dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + v[1][i];
		}
		int ans = max(dp[0][n],dp[1][n]);
		cout << ans << '\n';
	}
}
