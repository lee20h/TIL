#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;
int arr[1001][1001];
bool visited[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	int cnt = -1;
	cin >> m >> n;
	for (int i=0; i<n; i++) { //n
		for (int j=0; j<m; j++) { //m
			cin >> arr[i][j];
			if(arr[i][j] == 1) {
				q.push(make_pair(i,j));
				visited[i][j] = true;
			}
			else if(arr[i][j] == -1)
				visited[i][j] = true;
		}
	}
	
	while(!q.empty()) {
		int size = q.size();
		cnt++;
		while(size--) {
			pair<int,int>cur = q.front();
			q.pop();
			for (int i=0; i<4; i++) {
				int qx, qy;
				qx = cur.second + dx[i];
				qy = cur.first + dy[i];
				if(qx < 0 || qy < 0 || qx >= m || qy >= n)
					continue;
				if(!visited[qy][qx] && arr[qy][qx] == 0) {
					visited[qy][qx] = true;
					q.push(make_pair(qy,qx));
				}
			}
		}
	}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++){
				if(!visited[i][j]) {
					cout << "-1";
					return 0;
				}
			}
		}
		
	cout << cnt;
}
