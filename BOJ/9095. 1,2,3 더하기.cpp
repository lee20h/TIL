#include <iostream>
#include <cstring>
using namespace std;

int dp[11];

int sol(int n) {
	if(n==0) return 0;
	else if(n==1) return 1;
	else if(n==2) return 2;
	else if(n==3) return 4;
	if(dp[n] == -1)
		return dp[n] = sol(n-1) + sol(n-2) + sol(n-3);
	else return dp[n];
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(dp,-1,sizeof(dp));
	int t, n;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		cout << sol(n) << '\n';
	}
}
