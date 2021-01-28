#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;

int k, w, h;
int arr[MAX][MAX];
bool visited[MAX][MAX][30+2];

int py[4] = {0, 0, 1, -1};
int px[4] = {1, -1, 0, 0};
int ky[8] = {-2, -1, 1, 2, 1, 2, -1 ,-2};
int kx[8] = {-1, -2, -2, -1, 2, 1, 2, 1};

int bfs(int y, int x) {
	queue<pair<pair<int ,int>, pair<int, int>>> q;
	q.push({{y,x},{0,0}});
	visited[y][x][0] = true;
	
	while(!q.empty()) {
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int knight = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if(curY == h-1 && curX == w-1)
			return cnt;
			
		if(knight < k) {
			for (int i=0; i<8; i++) {
				int dy = curY + ky[i];
				int dx = curX + kx[i];
				
				if(0 > dy || 0 > dx || h <= dy || w <= dx)
					continue;
				if(visited[dy][dx][knight+1] && arr[dy][dx])
					continue;
				
				
				visited[dy][dx][knight+1] = true;
				q.push({{dy,dx},{knight+1, cnt+1}});
			}
		}
		
		for (int i=0; i<4; i++) {
			int dy = curY + py[i];
			int dx = curX + px[i];
			
			if(0 > dy || 0 > dx || h <= dy || w <= dx)
				continue;
			if(visited[dy][dx][knight] && arr[dy][dx])
				continue;
			
			visited[dy][dx][knight] = true;
			q.push({{dy,dx},{knight, cnt+1}});
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> w >> h;
	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << bfs(0,0);
}
