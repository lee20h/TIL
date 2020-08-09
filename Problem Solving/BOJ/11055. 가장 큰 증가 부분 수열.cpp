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
		dp[i] = arr[i];
	}
	int ans = dp[0];
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[i] < arr[i] + dp[j])
				dp[i] = arr[i] + dp[j];
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
} 
