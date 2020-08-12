#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;

int person[MAX];
bool visited[MAX];
bool done[MAX];
int cnt;

void dfs(int n) {
	visited[n] = true;
	int next = person[n];
	if(!visited[next])
		dfs(next);
	else if (!done[next]) {
		for (int i=next; i!=n; i = person[i])
			cnt++;
		cnt++;
	}
	done[n] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		int n;
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> person[i];
		}
		cnt = 0;
		for (int i=1; i<=n; i++) {
			if(!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt << '\n';
	}
}
