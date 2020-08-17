#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;
const int MAX_d = 17; // 2^17승이 10만이 넘는 최소의 2의 제곱승 

int depth[MAX];
int parent[MAX][MAX_d]; // MAX번 노드의 2^MAX_d번째 조상 
int n, m, d;

vector<int> v[MAX];

void dfs(int now, int cnt) {
	depth[now] = cnt++;
	for (int i=1; i<=d; i++)
		parent[now][i] = parent[parent[now][i-1]][i-1];
	for (int i=0; i<v[now].size(); i++) {
		if(!depth[v[now][i]]) {
			parent[v[now][i]][0] = now;
			dfs(v[now][i], cnt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (d = 1; (1 << d) <= n; d++);
	d--;
	
	while(--n) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,1);
	
	cin >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		if(depth[a] < depth[b])
			swap(a,b);
		
		for(int i=d; i>=0; i--)
			if(depth[b] <= depth[parent[a][i]])
				a = parent[a][i];
				
		if (a == b) {
			cout << a << '\n';
			continue;
		}
		for (int i=d; i>=0; i--) {
			if(parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		cout << parent[a][0] << '\n';
	}
}
