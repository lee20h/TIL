#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;

int v[MAX][3];
int best[2][3];
int worst[2][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<3; j++)
			cin >> v[i][j];
	}
	
	for (int i=1; i<=n; i++) {
		int prev = (i-1) % 2;
		int curr = i % 2;
	
		best[curr][0] = max(best[prev][0],best[prev][1]) + v[i][0];
		best[curr][1] = max(max(best[prev][0],best[prev][1]),best[prev][2]) + v[i][1];
		best[curr][2] = max(best[prev][1],best[prev][2]) + v[i][2];
		
		worst[curr][0] = min(worst[prev][0],worst[prev][1]) + v[i][0];
		worst[curr][1] = min(min(worst[prev][0],worst[prev][1]),worst[prev][2]) + v[i][1];
		worst[curr][2] = min(worst[prev][1],worst[prev][2]) + v[i][2];
	}
	int curr = n % 2;
	cout << max(max(best[curr][0],best[curr][1]),best[curr][2]) << ' ' << min(min(worst[curr][0],worst[curr][1]),worst[curr][2]);
}
