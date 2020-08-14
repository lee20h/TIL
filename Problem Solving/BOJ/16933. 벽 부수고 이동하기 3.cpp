#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
bool visited[MAX][MAX][11];
int pos[4] = {-1,0,1,0};
int pos2[4] = {0,-1,0,1};

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
	q.push({{1,1},{0,0}});
	visited[1][1][0] = true;
	int ans = -1;
	while(!q.empty()) {
		int ypos = q.front().first.first;
		int xpos = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		
		q.pop();
		
		if(ypos == n && xpos == m) {
			ans = cnt + 1;
			break;
		}
		for (int i=0; i<4; i++) {
			int y = ypos + pos[i];
			int x = xpos + pos2[i];
			
			if(y > n || x > m || y < 1 || x < 1)
				continue;
			
			if(arr[y][x] == 1 && wall < k && !visited[y][x][wall+1]) {
				if(cnt % 2 == 0) {
					q.push({{y,x},{wall+1, cnt+1}});
					visited[y][x][wall+1] = true;
				}
				else if(cnt % 2 == 1) {
					q.push({{ypos,xpos},{wall,cnt+1}});
				}
			}
			else if(arr[y][x] == 0 && !visited[y][x][wall]) {
				q.push({{y,x},{wall, cnt+1}});
				visited[y][x][wall] = true;
			}
		}
	}
	cout << ans;
	
}
