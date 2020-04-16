#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[501];
bool visited[501];

void dfs(int start) {
	for (int i=0; i<v[start].size(); i++) {
		visited[v[start][i]] = true;
	}
	if(start == 1) {
		for (int i=0; i<v[start].size(); i++) {
			dfs(v[start][i]);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int m;
	cin >> m;
	int a,b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int ans = 0;
	for (int i=2; i<=n; i++) {
		if(visited[i]) ans++;
	}
	cout << ans;
}
