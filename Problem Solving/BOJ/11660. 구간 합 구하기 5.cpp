#include <bits/stdc++.h>
using namespace std;

int dp[1025][1025];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int num;
			cin >> num;
			
			dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + num;
			
		}
	}
	for (int i=0; i<m; i++) {
		int x1, x2 ,y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1] << '\n';
	}
}
