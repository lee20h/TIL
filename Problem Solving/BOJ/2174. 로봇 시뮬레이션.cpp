#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 2;

int board[MAX][MAX];

int px[4] = {-1, 0, 1, 0};
int py[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, n, m;
	int robot = 0, wall = 0, crashRobot = 0;
	cin >> a >> b >> n >> m;
	vector<pair<pair<int,int>, int>> v;
	v.push_back({{0,0}, 0});
	for (int i=1; i<=n; i++) {
		int y, x, intDir;
		char dir;
		cin >> x >> y >> dir;
		if(dir == 'N')
			intDir = 1;
		else if (dir == 'E')
			intDir = 2;
		else if (dir == 'S')
			intDir = 3;
		else
			intDir = 0;
		v.push_back({{x,y},intDir});
		board[x][y] = i;
	}
	
	for (int i=0; i<m; i++) {
		int num, repeat;
		char cmd;
		
		cin >> num >> cmd >> repeat;
		
		if(wall || robot)
			continue;
			
		int dx = v[num].first.first;
		int dy = v[num].first.second;
		int dir = v[num].second;
		while(repeat--) {
			
			if(cmd == 'F') {
				board[dx][dy] = 0;
				dx += px[dir];
				dy += py[dir];
				if(dy < 1 || dx < 1 || dy > b || dx > a) {
					wall = num;
					break;
				}
				if(board[dx][dy]) {
					robot = num;
					crashRobot = board[dx][dy];
					break;
				}
				board[dx][dy] = num;
				v[num] = {{dx, dy}, dir};
			}
			else if(cmd == 'R') {
				dir = (dir + 1) % 4;
				v[num] = {{dx, dy}, dir};
			}
			else if (cmd == 'L') {
				dir = (dir + 3) % 4;
				v[num] = {{dx, dy}, dir};
			}
		}
	}
	if(wall)
		cout << "Robot " << wall << " crashes into the wall";
	else if(robot)
		cout << "Robot " << robot << " crashes into robot " << crashRobot;
	else
		cout << "OK";
}
