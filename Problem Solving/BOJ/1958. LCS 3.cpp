#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int dp[MAX][MAX][MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b, c;
	int asize, bsize, csize;
	cin >> a >> b >> c;
	asize = a.size();
	bsize = b.size();
	csize = c.size();
	
	for (int i=1; i<=asize; i++) {
		for (int j=1; j<=bsize; j++) {
			for (int k=1; k<=csize; k++) {
				if(a[i-1] == b[j-1] && b[j-1] == c[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else {
					dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
				}
			}
		}
	}
	
	cout << dp[asize][bsize][csize];
}
