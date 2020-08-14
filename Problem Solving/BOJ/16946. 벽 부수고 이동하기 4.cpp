#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAX = 1000 + 1;

int map[MAX][MAX];
int n, m;
bool visit[MAX][MAX];
int resultmap[MAX][MAX];
int cnt;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void visitClear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;
}

void dfs(int y, int x, int comType) {
	cnt++;
	map[y][x] = comType;

	for (int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(nx<0 || ny<0 || nx==m || ny==n) 
			continue;
			
		if(visit[ny][nx] || map[ny][nx])
			continue;
		visit[ny][nx] = true;
		dfs(ny,nx,comType);
	}
}

int main() {
	cin >> n >> m;
	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
			if((temp -'0') == 1)
				map[i][j] = -1;
		}
	}

	//컴포넌트 자리 찾아주기
	vector<int>com = {0};
	int comtype = 0; // 1부터시작
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0) {
				comtype++;
				cnt = 0;
				dfs(i, j, comtype);
				com.push_back(cnt);
			}

	//순회하며 컴포넌트 합쳐주기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//벽일때
			if (map[i][j] == -1) {
				//상하좌우의 컴포넌트 구해준거 다합쳐주기, 중복 조심
				int sum = 0;
				set<int> used;
				
				for (int k=0; k<4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if(nx<0 || ny<0 || nx==m || ny==n) 
						continue;
					
					if(map[ny][nx] != -1 && used.count(map[ny][nx])==0) {
						used.insert(map[ny][nx]);
						sum += com[map[ny][nx]];
					}
					resultmap[i][j] = (sum + 1)%10;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << resultmap[i][j];
		}
		cout << '\n';
	}
}
