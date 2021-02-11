#include <bits/stdc++.h>
using namespace std;

const int MAX = 200 + 1;

int arr[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	
	for (int i=1; i<=n; i++) {
		dp[i] = 1;
		for (int j=1; j<=i; j++) {
			if(arr[j] < arr[i] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
		if(ans < dp[i])
			ans = dp[i];
	}
	cout << n - ans;
}
