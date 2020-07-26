#include <bits/stdc++.h>
using namespace std;

int v[1001];
int w[100001];
int dp[1001][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> v[i];
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			dp[i][j] = dp[i-1][j];
			if(j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][k];
}
