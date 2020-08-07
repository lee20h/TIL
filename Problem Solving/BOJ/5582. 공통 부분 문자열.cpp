#include <bits/stdc++.h>
using namespace std;

const int MAX = 4000 + 1;
int dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int asize, bsize;
	asize = a.size();
	bsize = b.size();
	int ans = 0;
	for (int i=1; i<=asize; i++) {
		for (int j=1; j<=bsize; j++) {
			if(a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans;
}
