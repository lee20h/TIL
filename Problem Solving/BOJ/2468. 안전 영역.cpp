#include <bits/stdc++.h>
using namespace std;

int n;
int v[100][100];
int pos[4] = {0,0,1,-1};
int pos2[4] = {1,-1,0,0};
bool visited[100][100]; 

void dfs(int y, int x, int h) {
	for (int i=0; i<4; i++) {
		int px = x + pos[i];
		int py = y + pos2[i];
		
		if(px < 0 || px >= n || py < 0 || py >= n) continue;
		if(v[py][px] <= h || visited[py][px]) continue;
		visited[py][px] = true;
		dfs(py, px, h);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int maxi = 0;
	int mini = 100;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> v[i][j];
			mini = min(mini, v[i][j]);
			maxi = max(maxi, v[i][j]);
		}
	}
	
	int answer = 1;
	for (int h=mini; h<maxi; h++) {
		memset(visited,false,sizeof(visited));
		int cnt = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if(h < v[i][j] && !visited[i][j]) {
					visited[i][j] = true;
					cnt++;
					dfs(i,j,h);
				}
			}
		}
		
		answer = max(answer,cnt);
	}
	cout << answer;
}
