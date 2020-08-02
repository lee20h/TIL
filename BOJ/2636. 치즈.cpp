#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
const int move1[4] = {-1, 1, 0, 0};
const int move2[4] = {0, 0, 1, -1};
int arr[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int rest[101];
int hour;
 
void bfs() {
	queue<pair<int,int>> q;
	memset(visited, false, sizeof(visited));
	q.push({1,1});
	visited[1][1] = true;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i=0; i<4; i++)	{
			int ny = y + move1[i];
			int nx = x + move2[i];
			
			if(ny < 1 || nx < 1 || nx > m || ny > n) continue;
			if(visited[ny][nx]) continue;
			if(arr[ny][nx] >= 1) {
				arr[ny][nx]++;
				continue;
			}
			q.push({ny,nx});
			visited[ny][nx] = true;
		}
	}
}

bool melt() {
	bool flag = false;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if(arr[i][j] >= 2) {
				arr[i][j] = 0;
				rest[hour]++;
				flag = true;
			}
			else if (arr[i][j] > 0) arr[i][j] = 1;
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<pair<int,int>> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	while(1) {
		bfs();
		if(melt())  {
			hour++;
		}
		else break;
	}	
	cout << hour << '\n' << rest[hour-1];
}
