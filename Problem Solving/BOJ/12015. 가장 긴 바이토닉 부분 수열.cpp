#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int arr[MAX];
int dp[MAX];
int dp_r[MAX];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		dp[i] = 1;
		dp_r[i] = 1;
	}
	
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i=n-2; i>=0; i--) {
		for (int j=n-1; j>=i; j--) {
			if(arr[j] < arr[i] && dp_r[i] < dp_r[j] + 1)
				dp_r[i] = dp_r[j] + 1;
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans = max(dp[i] + dp_r[i] - 1, ans);
	}
	cout << ans;
}
