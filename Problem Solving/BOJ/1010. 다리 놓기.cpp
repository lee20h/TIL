#include <iostream>
#include <cstring>
using namespace std;

long long dp[31][31];

long long sol(int n, int r) {
	if(n == r || r == 0) return 1;
	if(dp[n][r]) return dp[n][r];
	return dp[n][r] = sol(n-1, r-1) + sol(n-1,r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int cnt;
	cin >> cnt;

	for (int a = 0; a < cnt; a++) {
		cin >> n >> m;
		memset(dp,0,sizeof(dp));
		cout << sol(m,n) << endl;
	}
}
