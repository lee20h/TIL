#include <bits/stdc++.h>
using namespace std;

const int MAX = 1002;

char arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int ans = 0;
	cin >> n >> m;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if(arr[i-1][j-1] == '1') {
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
				ans = max(dp[i][j], ans);
			}
		}
	}
	
	cout << ans * ans;
}
