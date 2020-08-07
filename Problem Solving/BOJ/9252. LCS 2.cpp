#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int dp[MAX][MAX] = {0,};
string LCS[MAX][MAX];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	int n, m;
	cin >> a >> b;
	n = a.size();
	m = b.size();
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if(a[i-1] == b[j-1])  {
				dp[i][j] = dp[i-1][j-1] + 1;
				LCS[i][j] += LCS[i-1][j-1] + a[i-1];
			}
			else  {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if(dp[i][j] == dp[i-1][j])
					LCS[i][j] = LCS[i-1][j];
				else
					LCS[i][j] = LCS[i][j-1];
			}
		}
	}
	
	cout << dp[n][m] << '\n' << LCS[n][m];
}
