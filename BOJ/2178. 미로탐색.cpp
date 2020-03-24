#include <bits/stdc++.h>
using namespace std;

string v[101];
int h, w;
int pos[4] = {0,0,-1,1};
int pos2[4] = {1,-1,0,0};
bool visited[100][100];

void bfs() {
	int cnt=1;
	
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,1));
	visited[0][0] = true;
	while(!q.empty()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		cnt = get<2>(q.front());
 		q.pop();
		for (int i=0; i<4; i++) {
			int xpos = x+pos[i];
			int ypos = y+pos2[i];
			if(xpos<0 || xpos>=w || ypos<0 || ypos>=h) {
				continue;
			}
			if(visited[ypos][xpos] || v[ypos][xpos] == '0')
				continue;
			q.push(make_tuple(ypos,xpos,cnt+1));
			visited[ypos][xpos] = true;
		}
		if (x==w-1 && y==h-1) {
			cout << cnt;
			break;
		}
	}
}

int main() {
	cin >> h >> w;
	for (int i=0; i<h; i++) {
		cin >> v[i];
	}
	bfs();
	return 0;
	
	
} 
