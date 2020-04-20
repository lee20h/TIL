#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

typedef struct {
	int y,x;
}Dir;
typedef struct {
	int time, y, x;
}path;
Dir Dirmove[4] = { {-1,0}, {0,-1}, {0,1}, {1,0}};

bool operator<(const path &p1, const path &p2) {
	if (p1.time > p2.time)
		return true;
	else if (p1.time == p2.time && p1.y > p2.y)
		return true;
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x)
		return true;
	return false;
}
int v[MAX][MAX];
bool visited[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	pair<int,int> start;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> v[i][j];
			if(v[i][j] == 9) { // 상어의 위치 
				start = make_pair(i,j);
				v[i][j] = 0; //초기화 
			}
		}
	}
	queue<pair<pair<int,int>,int>> q; // 아기상어 
	q.push({{start},2});
	int ans = 0; // 답 
	int cnt = 0; //먹은 생선 
	
	while(!q.empty()) { //아기상어 기준 
		int y = q.front().first.first;
		int x = q.front().first.second;
		int size = q.front().second;
		q.pop();
		
		memset(visited, false, sizeof(visited)); // 반복마다 초기화 
		
		priority_queue<path> temp;
		temp.push({0,y,x}); // time, y, x
		visited[y][x] = true;
		
		while(!temp.empty()) { // 거리 기 준 
			int dist = temp.size(); //같은 거리 모두 비교 
			priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
			for (int d = 0; d < dist; d++) { 
				int curY = temp.top().y;
				int curX = temp.top().x;
				int curTime = temp.top().time;
				temp.pop();
				
				for (int i=0; i<4; i++) { // 4방향 체크 
					int nextY = curY + Dirmove[i].y;
					int nextX = curX + Dirmove[i].x;
					
					if(nextY >= 0 && nextY < n && nextX >= 0 && nextX < n) {
						if (!visited[nextY][nextX]) { //방문여부 
							if(v[nextY][nextX] <= size) { //지나갈 수 있나 
								temp.push({ curTime + 1, nextY, nextX});
								visited[nextY][nextX] = true;
								if (v[nextY][nextX] >= 1 && v[nextY][nextX] < size) // 먹이후보 
									pq.push({ {nextY, nextX}, curTime + 1});
							}
						}
					}
				}
			}
			
			if(!pq.empty()) {  // 우선순위가 제일 높은 먹이 섭취 
				cnt++;
				
				if (cnt == size) {
					q.push({ {pq.top().first}, size + 1});
					cnt = 0;
				}
				else q.push({ {pq.top().first}, size});
				
				v[pq.top().first.first][pq.top().first.second] = 0; // 배열에서 고기 없게 표시
				ans += pq.top().second;
				break; 
			}
		}
	}
	cout << ans;
}
