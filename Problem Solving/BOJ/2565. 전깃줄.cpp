#include <bits/stdc++.h>
using namespace std;

const int MAX = 100+1;

vector<pair<int,int>> line;
vector<int> v;
vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({a,b});
	}
	sort(line.begin(), line.end());
	
	for (int i=0; i<n; i++) {
		dp.push_back(1);
		v.push_back(line[i].second);
	}
	int ans = 0;
	for(int i=1; i<n; i++) {
		for (int j=0; j<=i; j++) {
			if(v[i] > v[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j]+1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}
