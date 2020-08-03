#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> tree[10000];
int ans = -1;
bool visited[10001];
int max_leaf = 0;

void dfs(int node, int cost) {
	if(visited[node]) return;
	visited[node] = true;
	
	if(ans < cost) {
		ans = cost;
		max_leaf = node;
	}
	
	for (int i=0; i<tree[node].size(); i++) {
		dfs(tree[node][i].first, tree[node][i].second + cost);
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		tree[v1].push_back({v2, cost});
		tree[v2].push_back({v1, cost});
	}
	dfs(1,0);
	for (int i=1; i<=n; i++)
		visited[i] = false;
	dfs(max_leaf,0);
	cout << ans;
}
