#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

int py[4] = {0, 0, 1, -1};
int px[4] = {1, -1, 0, 0};

char arr[MAX][MAX];
int cache[MAX][MAX];
int w, h;

int bfs(int a, int b) {
	int ans = 0;
	queue<pair<int,int>> q;
	q.push({a,b});
	memset(cache, 0, sizeof(cache));
	cache[a][b] = 1;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i=0; i<4; i++) {
			int dy = y + py[i];
			int dx = x + px[i];
			ans = max(ans, cache[y][x]);
			if(dy < 0 || dx < 0 || dy >= h || dx >= w)
				continue;
			if(arr[dy][dx] == 'W' || cache[dy][dx])
				continue;
			q.push({dy,dx});
			cache[dy][dx] = cache[y][x] + 1;
		}
	}
	
	return ans-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> h >> w;
	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if(arr[i][j] == 'L')
				ans = max(ans,bfs(i, j));
		}
	}
	
	cout << ans;
}
