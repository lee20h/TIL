#include <bits/stdc++.h>
using namespace std;

queue<pair<pair<int,int>,int>> q;
int arr[101][101][101];
bool visited[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, h;
	int cnt = -1;
	cin >> m >> n >> h;
	for (int k=0; k<h; k++) { //h
		for (int i=0; i<n; i++) { //n
			for (int j=0; j<m; j++) { //m
				cin >> arr[i][j][k];
				if(arr[i][j][k] == 1) {
					q.push(make_pair(make_pair(i,j),k));
					visited[i][j][k] = true;
				}
				else if(arr[i][j][k] == -1)
					visited[i][j][k] = true;
			}
		}
	}
	
	while(!q.empty()) {
		int size = q.size();
		cnt++;
		while(size--) {
			
			pair<pair<int,int>,int> cur = q.front();
			q.pop();
			
			for (int i=0; i<6; i++) {
				int qx, qy ,qz;
				qx = cur.first.second + dx[i];
				qy = cur.first.first + dy[i];
				qz = cur.second + dz[i];
				if(qx < 0 || qy < 0 || qz < 0 || qx >= m || qy >= n || qz >= h)
					continue;
				if(!visited[qy][qx][qz] && arr[qy][qx][qz] == 0) {
					visited[qy][qx][qz] = true;
					q.push(make_pair(make_pair(qy,qx),qz));
				}
			}
		}
		
	}
	
	for (int k=0; k<h; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++){
				if(!visited[i][j][k]) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	cout << cnt;
}
