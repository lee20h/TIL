#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

vector<pair<int,int>> v[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC;
	cin >> TC;
	while(TC--) {
		int n, m, w;
		cin >> n >> m >> w;
		
		for (int i=1; i<=n; i++)
			v[i].clear();
		
		
		for (int i=0; i<m; i++) {
			int v1, v2, cost;
			cin >> v1 >> v2 >> cost;
			v[v1].push_back({v2, cost});
			v[v2].push_back({v1, cost});
		}
		for (int i=0; i<w; i++) {
			int v1, v2, cost;
			cin >> v1 >> v2 >> cost;
			v[v1].push_back({v2,-cost});
		}
		
		int dist[501] = {INF,};
		dist[1] = 0;
		bool check = false;
		for(int q=0; q<n; q++) {
			check = false;
			for (int i=1; i<=n; i++){
				for (int j=0; j<v[i].size(); j++) {
					int edge = v[i][j].first;
					int cost = v[i][j].second;
					
					if(dist[edge] > dist[i] + cost) {
						dist[edge] = dist[i] + cost;
						check = true;
					}
				}
			}
			if(!check) {
				cout << "NO\n";
				break;
			}
		}
		if(check) cout << "YES\n";
	}
}
