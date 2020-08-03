#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int dp[10003] = {0,};
	int v[10003];
	for (int i=3; i<n+3; i++) cin >> v[i];
	
	for (int i=3; i<n+3; i++) {
		dp[i] = max(dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]);  
		dp[i] = max(dp[i-1], dp[i]); // 두번 연속 안 마시는 경우 
		
	}
	cout << dp[n+2]; 
}
