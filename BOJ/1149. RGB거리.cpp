#include <bits/stdc++.h>
using namespace std;

int v[1001][3];
int dp[1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
			cin >> v[i][j];
	
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	
	for (int i=1; i<n; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i][2];
	}
	
	int ans = 987654321;
	for (int i=0; i<3; i++) {
		if(ans > dp[n-1][i]) ans = dp[n-1][i];
	}
	cout << ans;
}
