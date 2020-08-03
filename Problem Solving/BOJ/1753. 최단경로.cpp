#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1e9

vector<pair<int,int>> v[20001];
int dist[20001];
int start;

void sol() {
	priority_queue< pair<int,int>> q;
	q.push(make_pair(0,start));
	while(!q.empty()) {
		int node = q.top().second;
		int cost = -1 * q.top().first;
		q.pop();
		if(dist[node] < cost) continue;
		
		for (int i=0; i<v[node].size(); i++) {
			int next_node = v[node][i].second;
			int next_cost = v[node][i].first + cost;
			
			if(dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				q.push(make_pair(-1 * next_cost, next_node));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m >> start;
	n++;
	for (int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back(make_pair(w,y));
	}
	
	
	for (int i=1; i<=n; i++)
		dist[i] = INF;
	dist[start] = 0;
	
	sol();
	
	for (int i=1; i<n; i++) {
		if(dist[i] == INF) {
			cout << "INF\n";
		}
			
		else
			cout << dist[i] << '\n';
	}
	
}
