#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 15 + 1;
int n;
int arr[MAX][MAX];
int dp[MAX][1<<MAX];

int tsp(int cur, int visited) {
	int& ret = dp[cur][visited];
	if(ret != -1)
		return ret;
		
	if(visited == (1<<n)-1) {
		if(arr[cur][0] != 0)
			return arr[cur][0];
		else
			return INF;
	}
	
	ret = INF;
	for (int i=0; i<n; i++) {
		if(arr[cur][i] && !(visited & (1 << i))) {
			int visit = visited | (1 << i);
			ret = min(ret, tsp(i, visit) + arr[cur][i]);
		}
	}
	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans = tsp(0,1);
	cout << ans;
}
