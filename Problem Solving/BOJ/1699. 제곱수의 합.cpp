#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int main() {
	int n;
	cin >> n;
	for (int i=0; i<100001; i++) {
		dp[i] = 10000000;
	}
	dp[0] = 0;
	for(int i=0; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if(i+j*j > n) break;
			dp[i+j*j] = min(dp[i+j*j],dp[i]+1);
		}
	}
	cout << dp[n];
}
