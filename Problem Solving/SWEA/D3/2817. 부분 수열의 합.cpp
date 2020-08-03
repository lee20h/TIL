#include <bits/stdc++.h>
using namespace std;

int n, sum, cnt;
int v[20];
bool visited[20];

void dfs(int num, int temp, int size) {
	if (sum == temp) {
		cnt++;
		return;
	}
	
	for (int i=num; i<n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			dfs(i, temp+v[i], size+1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		cnt = 0;
		cin >> n >> sum;
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		for (int i=0; i<n; i++) {
			if(!visited[i]) {
				visited[i] = true;
				dfs(i,v[i],1);
				visited[i] = false;
			}
		}
		cout << "#" << t << ' ' << cnt << '\n';
	}
}
