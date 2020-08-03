#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;
int table[MAX][MAX];
int cache[MAX][MAX][2];
int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
int n, m, ans = INF;

int sol() {
	queue<pair<pair<int,int>, int>> q;
	q.push({{1,1},1});
	cache[1][1][1] = 1;
	while(!q.empty()) {
		int ypos = q.front().first.first;
		int xpos = q.front().first.second;
		int block = q.front().second;
		q.pop();
		if(ypos == n && xpos == m) {
			return cache[ypos][xpos][block];
		}
		for (int i=0; i<4; i++) {
			int y = ypos + moveY[i];
			int x = xpos + moveX[i];
			
			if(x < 1 || y < 1 || x > m || y > n) continue;
			
			if(table[y][x] == 1 && block) { // 벽을 만났는데 뚫을 수 있음 
				cache[y][x][block-1] = cache[ypos][xpos][block] + 1;
				q.push({{y,x},block-1});
			}
			else if(table[y][x] == 0 && cache[y][x][block] == 0) { // 벽이 없고 방문하지 않음 
				cache[y][x][block] = cache[ypos][xpos][block] + 1;
				q.push({{y,x}, block});
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<pair<int,int>> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++){
			char temp;
			cin >> temp;
			table[i][j] = temp - '0';
		}
	}
	cout << sol();
}
