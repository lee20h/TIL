#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

int farm[MAX][MAX];
bool visited[MAX][MAX];
int n, m, k, T;
int pos[4] = {0, 0, 1, -1};
int pos2[4] = {1, -1, 0, 0};

void dfs(int y, int x) {
	
	for (int i=0; i<4; i++) {
		int posy = y + pos[i];
		int posx = x + pos2[i];
		
		if(posy < 0 || posx < 0 || posy >= n || posx >= m) continue;
		if(farm[posy][posx] == 1 && !visited[posy][posx]) {
			visited[posy][posx] = true;
			dfs(posy,posx);
		} 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		int insect = 0;
		cin >> m >> n >> k;
			
		memset(farm, 0, sizeof(farm));
		memset(visited, false, sizeof(visited));
		
		for (int i=0; i<k; i++) {
			int y, x;
			cin >> x >> y;
			farm[y][x] = 1;
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if(farm[i][j] == 1 && !visited[i][j]) {
					insect++;
					visited[i][j] = true;
					dfs(i,j);
				}
			}
		}
		cout << insect << '\n';
	}
}
