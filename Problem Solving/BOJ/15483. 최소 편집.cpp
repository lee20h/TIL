#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
	string a, b;
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	
	int alen = a.length();
	int blen = b.length();
	
	for (int i=0; i<alen; i++)
		dp[i][0] = i;
	for (int i=0; i<blen; i++) 
		dp[0][i] = i;
	
	for (int i=1; i<alen; i++) {
		for (int j=1; j<blen; j++) {
			if(a[i]==b[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min({ dp[i-1][j-1], dp[i][j-1], dp[i-1][j] }) + 1;
		}
	}
	cout << dp[alen-1][blen-1];
}
