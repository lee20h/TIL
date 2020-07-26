#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[100001];
const int INF = 987654321;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[1001];
int start_, end_, weight;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		dist[i] = INF; // 거리 다 INF로 초기화 
	} 
	for (int i=0; i<m; i++) {
		cin >> start_ >> end_ >> weight;
		v[start_].push_back({end_, weight});
	}
	cin >> start_ >> end_;
	
	dist[start_] = 0; // 시작지점 거리 0 
	
	pq.push({0,start_}); // 시작지점 우선순위 큐에 삽입 
	
	while(!pq.empty()) {
		int cur = pq.top().second; // 방문하지 않은 노드 중 가장 비용 낮은 노드 
		weight = pq.top().first;
		pq.pop();
		
		if(dist[cur] < weight) continue; // 이미 최소거리면 continue 
		
		for (int i=0; i<v[cur].size(); i++) { // 인접 노드들 dist 최소로 갱신 
			int adj = v[cur][i].first;
			int adjdist = v[cur][i].second + weight;
			
			if(dist[adj] > adjdist) { // dist보다 작은 거리면 pq에 갱신 
				dist[adj] = adjdist;
				pq.push({adjdist, adj});
			}
		}
	}
	cout << dist[end_];
}
