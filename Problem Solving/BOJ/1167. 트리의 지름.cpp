#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[100001];
bool visited[100001];
int ans = -1;
int max_p;

void dfs(int node, int sum) {
	if(visited[node]) return;
	visited[node] = true;
	if(ans < sum) {
		ans = sum;
		max_p = node;
	}
	for (int i=0; i<v[node].size(); i++) {
			dfs(v[node][i].first,sum + v[node][i].second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int vertex;
	int num;
	int temp = 0;
	cin >> vertex;
	for (int i=1; i<=vertex; i++) {
		cin >> num;
		while(1) {
			cin >> temp;
			if(temp == -1) break;
			int dist;
			cin >> dist;
			v[num].push_back({temp, dist});
			v[temp].push_back({num, dist});
		}
	}
	dfs(1, 0);
	for (int i=1; i<=vertex; i++) 
		visited[i] = false;
	dfs(max_p, 0);
	cout << ans;
}
