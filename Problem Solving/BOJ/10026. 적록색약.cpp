#include <bits/stdc++.h>
#include <cstring>
using namespace std;

char color[100][100];
bool visited[100][100];
int n;
int pos[4] = {1,-1,0,0};
int pos2[4] = {0,0,1,-1};

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i=0; i<4; i++) {
		int px, py;
		px = x + pos[i];
		py = y + pos2[i];
		if(px < 0 || py < 0 || px >= n || py >= n) continue;
		
		if(!visited[py][px] && color[py][px] == color[y][x]) {
			dfs(py,px);
		}
	}
}

void RGdfs(int y, int x) {
	visited[y][x] = true;
	for (int i=0; i<4; i++) {
		int px, py;
		px = x + pos[i];
		py = y + pos2[i];
		if(px < 0 || py < 0 || px >= n || py >= n) continue;
		
		if(!visited[py][px]) {
			if(color[y][x] == 'R' || color[y][x] == 'G') {
				if(color[py][px] == 'R' || color[py][px] == 'G')
					RGdfs(py,px);
			}
			else if(color[py][px] == color[y][x]) {
				RGdfs(py,px);
			}
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	int RGcnt = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> color[i][j];
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if(!visited[i][j]) {
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			visited[i][j] = false;
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if(!visited[i][j]) {
				RGdfs(i,j);
				RGcnt++;
			}
		}
	}
	
	cout << cnt << ' ' << RGcnt;
	
	
}
