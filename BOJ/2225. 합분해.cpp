#include <iostream>
#include <cstring>
using namespace std;

long long dp[201][201];
int main() {
	int n, cnt, k;
	cin >> n >> k;
	
	for (int i=1; i<=n; i++)
		dp[i][1] = 1;
	for (int i=1; i<=k; i++)
		dp[1][i] = i;
	for (int i=2; i<=n; i++) {
		for (int j=2; j<=k; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] % 1000000000;
		}
	}
	cout << dp[n][k] % 1000000000;
}
