#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int arr[MAX][MAX];
bool visited[MAX][MAX];
bool visited2[MAX][MAX]; // 검 주운 뒤 
int pos[4] = {1,-1,0,0};
int pos2[4] = {0,0,1,-1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	queue<pair<pair<int,int>,bool>> q;
	bool goal = false;
	q.push({ {0,0}, false});
	visited[0][0] = true;
	
	for (int p=0; p<=t; p++) {
		int size = q.size();
		for (int i=0; i<size; i++) {
			int y = q.front().first.first;
			int x = q.front().first.second;
			bool flag = q.front().second;
			q.pop();
			
			if(arr[y][x] == 2)
				flag = true;
			
			if(y == n-1 && x == m-1) {
				goal = true;
				break;
			}
			
			for (int j=0; j<4; j++) {
				int dx = x + pos[j];
				int dy = y + pos2[j];
				
				if(dx < 0 || dy < 0 || dx >= m || dy >= n)
					continue;
				if(flag && visited2[dy][dx])
					continue;
				if(!flag && visited[dy][dx])
					continue;
				if(!flag && arr[dy][dx] == 1)
					continue;
				if(flag)
					visited2[dy][dx] = true;
				else
					visited[dy][dx] = true;
				
				q.push({{dy,dx}, flag});
			}
		}
		if(goal) {
			cout << p;
			break;
		}
	}
	if(!goal)
		cout << "Fail";
}
