#include <bits/stdc++.h>
using namespace std;

const int MAX = 50000+1;

int n, m;
int depth[MAX], parent[MAX];
vector<int> v[MAX];

void dfs(int now, int cnt) {
	depth[now] = cnt++;
	for (int i=0; i<v[now].size(); i++) {
		if(!depth[v[now][i]]) {
			dfs(v[now][i], cnt);
			parent[v[now][i]] = now;
		}
	}
		
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,1);
	
	cin >> m;
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		if(depth[a] < depth[b]) swap(a,b);
		while(depth[a] != depth[b]) a = parent[a];
		while(a != b) {
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
	}
	 
}
