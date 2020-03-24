#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int dp[301];

int main() {
	int n;
	cin >> n;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	dp[0] = v[0];
	dp[1] = max(v[1],v[0]+v[1]);
	dp[2] = max(v[0]+v[2],v[1]+v[2]);
	
	for(int i=3; i<n; i++) {
		dp[i] = max(dp[i-2]+v[i],dp[i-3]+v[i-1]+v[i]);
	}
	cout << dp[n-1];
}
