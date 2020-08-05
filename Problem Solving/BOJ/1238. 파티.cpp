#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

vector<pair<int,int>> v[1001];


vector<int> dijkstra(int start, int num) {
	vector<int> dist(num, INF);
	dist[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,start});
	
	while(!q.empty()) {
		int cost = q.top().first;
		int node = q.top().second;
		q.pop();
		
		if(dist[node] < cost) continue;
		
		for (int i=0; i<v[node].size(); i++) {
			int near = v[node][i].first;
			int nearcost = cost + v[node][i].second;
			
			if(dist[near] > nearcost) {
				dist[near] = nearcost;
				q.push({nearcost,near});
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	
	for (int i=0; i<m; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		v[start].push_back({end, time});
	}
	
	int ans = -1;
	vector<int> two = dijkstra(x,n+1);
	
	for (int i=1; i<=n; i++) {
		vector<int> one = dijkstra(i,n+1);
		int sum = one[x] + two[i];
		if (sum >= INF || sum < 0)
			continue;
			
		ans = max(ans, sum);
		
	}
	cout << ans;
}
