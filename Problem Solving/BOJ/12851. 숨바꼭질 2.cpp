#include <bits/stdc++.h>
using namespace std;

bool visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	queue<pair<int,int>> q;
	cin >> n >> k;
	q.push({n,0});
	visited[n] = true;
	while(!q.empty()) {
		if(q.front().first == k) {
			cout << q.front().second << '\n';
			int ans = 1;
			int time = q.front().second;
			q.pop();
			while(!q.empty()) {
				if(q.front().first == k && q.front().second == time)
					ans++;
				q.pop();
			}
			cout << ans;
			return 0;
		}
		int dist = q.front().first;
		int sec = q.front().second;
		q.pop();
		visited[dist] = true;
		
		if(dist >= 1 && !visited[dist-1])
			q.push({dist-1,sec+1});
		if(dist <= 99999 && !visited[dist+1])
			q.push({dist+1,sec+1});
		if(dist <= 50000 && !visited[dist*2])
			q.push({dist*2,sec+1});
	}
}
