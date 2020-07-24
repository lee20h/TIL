#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int ans[100001];
void sol(int node) {
	for (int i=0; i<v[node].size(); i++) {
		if(!visited[v[node][i]]) {
			visited[v[node][i]] = true;
			sol(v[node][i]);
			ans[v[node][i]] = node;
			visited[v[node][i]] = false;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	visited[1] = true;
	sol(1);
	
	for (int i=2; i<=n; i++)
		cout << ans[i] << '\n';
}
