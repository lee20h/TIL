#include<iostream>
#include<vector>
using namespace std;

vector<int> edge[20001];
int visited[20001];
bool answer;
void dfs(int start, int color) {
	if(answer)
		return;
	if(visited[start] != 0) return;
	
	visited[start] = color;
	
	
	for (int i=0; i<edge[start].size(); i++) {
		if (color == visited[edge[start][i]]) {
			answer = true;
			return;
		}
		else if(visited[edge[start][i]] == 0)
			color==1?dfs(edge[start][i],2) : dfs(edge[start][i],1);
	}
}

int main() {
	int testcase;
	int v, e;
	int a, b;
	cin >> testcase;
	for (int t=0; t<testcase; t++) {
		answer = false;
		cin >> v >> e;
		for (int i=1; i<=v; i++) {
			visited[i] = 0;
			edge[i].clear();
		}
		for(int i=0; i<e; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(int i=1; i<=v; i++) {
			if(visited[i]!=0)
				continue;
			dfs(i,1);	
		}
		
		if(answer)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
