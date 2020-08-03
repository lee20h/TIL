#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp = 0;
	int dp[500][500] = {0,};
	
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			cin >> dp[i][j];
		}
	}
			
	for (int i=1; i<n; i++) {
		for (int j=0; j<=i; j++) {
			if (j==0) dp[i][j] = dp[i-1][0] + dp[i][j];
			else if (j==i) dp[i][j] = dp[i-1][j-1] + dp[i][j];
			else dp[i][j] = max(dp[i-1][j-1] + dp[i][j] , dp[i-1][j] + dp[i][j]);
			
			temp = max(temp,dp[i][j]);
		}
	}
	cout << temp;
}
