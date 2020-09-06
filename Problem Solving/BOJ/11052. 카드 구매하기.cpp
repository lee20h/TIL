#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000+1;

int p[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			dp[i] = max(dp[i],dp[i-j]+p[j]);
		}
	}
	cout << dp[n];
}
