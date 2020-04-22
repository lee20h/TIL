#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
bool visited[8];
int arr[8];

void dfs(int idx) {
	if(idx == m) {
		for (int i=0; i<m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i=0; i<n; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		arr[idx] = v[i];
		dfs(idx+1);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(),v.end());
	
	dfs(0);
}
