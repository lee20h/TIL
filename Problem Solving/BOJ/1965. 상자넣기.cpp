#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int arr[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	int ans = 0;
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
}
