#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
const int INF = 1e9;

int item[MAX];
int graph[MAX][MAX];
int ans = -1;
int n, m, r;

void init() {
	for (int i=1; i<MAX; i++) {
		for (int j=1; j<MAX; j++) {
			if(i != j)
				graph[i][j] = INF;
		}
	}
}
void floyd() {
	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if(graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	cin >> n >> m >> r;
	
	for (int i=1; i<=n; i++) {
		cin >> item[i];
	}
	
	for (int i=0; i<r; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
	}
	floyd();
	
	for (int i=1; i<=n; i++) {
		int sum = item[i];
		for (int j=1; j<=n; j++) {
			if(i == j)
				continue;
			if(graph[i][j] <= m) 
				sum += item[j];
		}
		ans = max(ans,sum);
	}
	cout << ans;
}

