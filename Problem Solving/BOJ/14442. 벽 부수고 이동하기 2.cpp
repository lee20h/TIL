#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
bool visited[MAX][MAX][11];
int pos[4] = {0,0,1,-1};
int pos2[4] = {1,-1,0,0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{1,1},{0,1}});
	visited[1][1][0] = true;
	
	while(!q.empty()) {
		int ypos = q.front().first.first;
		int xpos = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		
		q.pop();
		
		if(ypos == n && xpos == m) {
			cout << cnt;
			return 0;
		}
		
		for (int i=0; i<4; i++) {
			int y = ypos + pos[i];
			int x = xpos + pos2[i];
			
			if(y > n || x > m || y < 1 || x < 1)
				continue;
				
			if(visited[y][x][wall]) continue;
			
			if(arr[y][x] == 1 && wall < k) {
				q.push({{y,x},{wall+1, cnt+1}});
				visited[y][x][wall+1] = true;
			}
			if(arr[y][x] == 0) {
				q.push({{y,x},{wall, cnt+1}});
				visited[y][x][wall] = true;
			}
		}
	}
	cout << "-1";
	
}
