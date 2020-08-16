#include <bits/stdc++.h>
using namespace std;

const int MAX = 50 + 1;
const int KEY = 6;

int n,m;
string Map[MAX];
bool visited[MAX][MAX][1<<KEY];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int bfs(int startY, int startX) {
	queue<pair<pair<int,int>,pair<int,int>>> q; // y,x , cnt,key
	q.push({{startY, startX},{0,0}});
	visited[startY][startX][0] = true;
	
	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int key = q.front().second.second;
		q.pop();
		
		if(Map[y][x] == '1')
			return cnt;
			
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if(visited[ny][nx][key])
				continue;
			if(Map[ny][nx] == '#')
				continue;
				
			if(Map[ny][nx] == '.' || Map[ny][nx] == '0' || Map[ny][nx] == '1') {
				visited[ny][nx][key] = true;
				q.push({{ny,nx},{cnt+1, key}});
			}
			else if('a' <= Map[ny][nx] && Map[ny][nx] <= 'f') {
				int newkey = key | (1 << (Map[ny][nx] - 'a'));
				if(!visited[ny][nx][newkey]) {
					visited[ny][nx][key] = true;
					visited[ny][nx][newkey] = true;
					q.push({{ny,nx},{cnt+1,newkey}});
				}
			}
			else if('A' <= Map[ny][nx] && Map[ny][nx] <= 'F') {
				if(key & 1 << (Map[ny][nx] - 'A')) {
					visited[ny][nx][key] = true;
					q.push({{ny,nx}, {cnt+1, key}});
				}
			}
		}
		
		
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	string temp;
	int startY, startX;
	for (int i=0; i<n; i++) {
		cin >> Map[i];
		for (int j=0; j<Map[i].length(); j++) {
			if(Map[i][j] == '0') {
				startY = i;
				startX = j;
			}
		}
 	}
 	cout << bfs(startY,startX);
}
