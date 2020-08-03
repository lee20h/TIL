#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAX = 800 + 1;
vector<pair<int,int>> v[MAX];

vector<int> dijkstra(int start, int vertex) {
	
	vector<int> dist(vertex);
	for (int i=0; i<vertex; i++)
		dist[i] = INF;
	
	dist[start] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,start});
	
	while(!q.empty()) {
		int node = q.top().second;
		int cost = q.top().first;
		q.pop();
		
		if(dist[node] < cost) continue;
		
		for (int i=0; i<v[node].size(); i++) {
			int adj = v[node][i].first;
			int adjcost = cost + v[node][i].second;
			
			if(dist[adj] > adjcost) {
				dist[adj] = adjcost;
				q.push({adjcost,adj});
			}
		}
	}
	return dist;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, e;
	cin >> n >> e;
	
	n++;
	
	for (int i=0; i<e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	int v1, v2;
	cin >> v1 >> v2;
	
	vector<int> result = dijkstra(1,n);
	vector<int> temp1 = dijkstra(v1,n);
	vector<int> temp2 = dijkstra(v2,n); // 1 -> v1 -> v2 -> n or 1 -> v2 -> v1 -> n
	int ans = min(result[v1] + temp1[v2] + temp2[n-1], result[v2] + temp2[v1] + temp1[n-1]);
	if (ans >= INF || ans < 0) cout << -1;
	else cout << ans;
}
