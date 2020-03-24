#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[1001];
bool visited[1001];

void dfs(int start) {
	visited[start] = true;
	
	for (int i=0; i<edge[start].size(); i++) {
		if(!visited[edge[start][i]]) {
			dfs(edge[start][i]);
		}
	}
	
}

int main() {
	int n, m;
	int u, v;
	int answer = 0;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u); 
	}
	
	for (int i=1; i<=n; i++) {
		if(!visited[i]) {
			
			dfs(i);
			answer++;
		}
	}
	cout << answer;
}
