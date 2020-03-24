#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int> edge[1001];
queue<int> q;

void dfs(int start) {
	visited[start] = true;
	cout << start << ' ';
	for(int i=0; i<edge[start].size(); i++) {
		if(!visited[edge[start][i]]) {
			dfs(edge[start][i]);
		}
	}
}

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while(!q.empty()) {
		start = q.front();
		cout << start << ' ';
		q.pop();
		for (int i=0; i<edge[start].size(); i++) {
			if(!visited[edge[start][i]]) {
				q.push(edge[start][i]);
				visited[edge[start][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	int a, b;
	cin >> n >> m >> v;
	
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i=0; i<1002; i++) {
		sort(edge[i].begin(),edge[i].end());
	}
	dfs(v);
	cout << '\n';
	for(int i=0; i<1002; i++)
		visited[i] = false;
	bfs(v);
}
