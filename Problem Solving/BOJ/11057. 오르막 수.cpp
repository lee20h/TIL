#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[10][10][1000];
int dfs(int prev, int cur, int count) {
	if(prev>cur) return 0;
	if(n==count+1) {
		return 1;
	}
	int& ret = dp[prev][cur][count];
	if(ret != -1) return ret;
	ret = 0;
	for (int i=cur; i<=9; i++) {
		ret += dfs(cur,i,count+1);
	}
	return ret%=10007;
}

int main() {
	cin >> n;
	int ans = 0;
	memset(dp,-1,sizeof(dp));
	for (int i=0; i<=9; i++) {
		ans += dfs(0,i,0);
		ans = ans % 10007;
	}
	cout << ans;
}
