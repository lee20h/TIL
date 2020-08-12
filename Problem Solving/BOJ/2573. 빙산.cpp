#include <bits/stdc++.h>
using namespace std;

const int MAX = 300;

int sea[MAX][MAX];
bool visited[MAX][MAX];
int pos[4] = {0,0,1,-1};
int pos2[4] = {1,-1,0,0};
int ans = 1;
int n, m;

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i=0; i<4; i++) {
		int dy = y + pos[i];
		int dx = x + pos2[i];
		
		if(dy < 1 || dx < 1 || dy >= n-1 || dx >= m-1) continue;
		if(visited[dy][dx]) continue;
		if(sea[dy][dx]) dfs(dy,dx);
	}
}

void yearafter() {
	int sea_copy[MAX][MAX];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			sea_copy[i][j] = sea[i][j];
		}
	}
	for (int i=1; i<n-1; i++) {
		for (int j=1; j<m-1; j++) {
			if(sea_copy[i][j]) {
				int cnt = 0;
				for (int k=0; k<4; k++) {
					int y = i + pos[k];
					int x = j + pos2[k];
					if(sea_copy[y][x] == 0)
						cnt++;
				}
				sea[i][j] = max(sea_copy[i][j] - cnt, 0);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int ans = 0;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> sea[i][j];
		}
	}
	
	while(1) {
		memset(visited, false, sizeof(visited));
		bool flag = false;
		int cnt = 0;
		for (int i=1; i<n-1; i++) {
			for (int j=1; j<m-1; j++) {
				if(sea[i][j] && !visited[i][j]) {
					cnt++;
					if(cnt==2) {
						flag = true;
						break;
					}
					dfs(i,j);
				}
			}
			if(flag) break;
		}
		if(flag) break;
		
		if(cnt == 0) {
			ans = 0;
			break;
		}
		
		yearafter();
		ans++;
	}
	cout << ans;
}
