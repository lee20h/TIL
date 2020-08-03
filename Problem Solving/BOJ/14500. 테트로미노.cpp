#include <bits/stdc++.h>
using namespace std;

int paper[500][500];
bool visited[500][500];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

void dfs(int d, int y, int x, int sum) {
	if(d==4) {
		ans = max(ans, sum);
		return;
	}
	for (int i=0; i<4; i++){
		int px = x + dx[i];
		int py = y + dy[i];
		
		if(px<0 || py<0 || px>=m || py>=n) continue;
		if(visited[py][px]) continue;
		visited[py][px] = true;
		dfs(d+1, py, px, sum + paper[py][px]);
		visited[py][px] = false;
		
	}
}

void sol2(int y, int x) {
	int sum = 0;

    if (y >= 1 && x >= 1 && x < m-1) // で 
    	sum = max(sum, paper[y][x - 1] + paper[y][x] + paper[y - 1][x] + paper[y][x + 1]);
    if (y >= 0 && y < n - 1 && x < m - 1) // ぬ 
        sum = max(sum, paper[y][x - 1] + paper[y][x] + paper[y + 1][x] + paper[y][x + 1]);
    if (y >= 1 && y < n - 1 && x < m - 1) // た 
	    sum = max(sum, paper[y - 1][x] + paper[y][x] + paper[y][x + 1] + paper[y + 1][x]);
    if (y >= 1 && y < n - 1 && x >= 1) //っ 
        sum = max(sum, paper[y - 1][x] + paper[y][x] + paper[y][x - 1] + paper[y + 1][x]);
	ans = max(ans,sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			visited[i][j] = true;
			dfs(1,i,j,paper[i][j]);
			sol2(i,j);
			visited[i][j] = false;
		}
	}
	cout << ans;
}
