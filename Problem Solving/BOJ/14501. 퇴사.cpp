#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<pair<int,int>> v(n+1);
	vector<int> dp(n+1);
	for (int i=1; i<=n; i++) {
		cin >> v[i].first >> v[i].second;
		dp[i] = v[i].second;
	}
	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<i; j++) {
			if(i-j >= v[j].first)
				dp[i] = max(v[i].second + dp[j], dp[i]);
		}
	}
	
	for (int i=1; i<=n; i++) {
		if(i + v[i].first > n + 1)
			continue;
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
