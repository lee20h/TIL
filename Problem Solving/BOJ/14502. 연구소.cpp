#include <bits/stdc++.h>
using namespace std;

int temp[9][9];
int arr[9][9];
int n, m;
int ans;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

void sol(int cnt) {
	if(cnt == 3) { // bfs
		queue<pair<int,int>> q; // y,x
		int virus[9][9];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				virus[i][j] = temp[i][j];
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if(virus[i][j] == 2)
					q.push({i,j});
			}
		}
		
		while(!q.empty()) {
			int ypos = q.front().first;
			int xpos = q.front().second;
			q.pop();
			
			for (int i=0; i<4; i++) {
				int posX = xpos + x[i];
				int posY = ypos + y[i];
				if(posX < 0 || posX == m || posY < 0 || posY == n) continue;
				if(virus[posY][posX] == 0) {
					virus[posY][posX] = 2;
					q.push({posY,posX});
				}
			}
		}
		int safety = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if(virus[i][j] == 0) 
					safety++;
			}
		}
		
		ans = max(ans,safety);
		
		return;
	}
	
	// dfs 
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if(temp[i][j] == 0) {
				temp[i][j] = 1;
				sol(cnt+1);
				temp[i][j] = 0;
			}
		}
	}
} 

int main() { // 벽이 3개 해야하므로 dfs로 벽을 각각 두는 상황을 만들며 벽이 3개면 bfs로 바이러스 창궐 후 각각 케이스 0 공간 갯수 체크 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if(arr[i][j] == 0) {
				for (int i=0; i<n; i++) {
					for (int j=0; j<m; j++) {
						temp[i][j] = arr[i][j];
					}
				}// 원본 복사 
				temp[i][j] = 1;
				sol(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << ans;
}
