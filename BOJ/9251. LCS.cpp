#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;

void lcs(int m, int n) {
	for (int i=0; i<m; i++) {
		dp[i][0] = 0;
	}
	for (int i=0; i<n; i++) {
		dp[0][i] = 0;
	}
	for (int i=1; i<m; i++) {
		for (int j=1; j<n; j++) {
			if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	string temp = " ";
	temp += a;
	a = temp;
	temp = " ";
	temp += b;
	b = temp;
	lcs(a.size(),b.size());
	cout << dp[a.size()-1][b.size()-1];
}
