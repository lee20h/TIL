#include <bits/stdc++.h>
using namespace std;

int arr[50][50];
int x[4] = {-1,1,0,0}; // W E S N
int y[4] = {0,0,1,-1};
int ccw[4] = {1,3,0,2}; // 반시계 E->N->W->S
int cw[4] = {1,2,0,3}; // 시계 	E->S->W->N

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, t;
	pair<int,int> air_top, air_bot;
	bool flag = false;
	cin >> r >> c >> t;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == -1) {
				if(flag)
					air_bot = {i,j};
				else
					air_top = {i,j};
				flag = true;
			}
		}
	}
	
	for (int time=0; time<t; time++) {
		
		queue<pair<int,int>> q;
		
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if(arr[i][j] > 0)
					q.push({i,j});
			}
		} 
		
		int copy[50][50] = {0,};
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				copy[i][j] = arr[i][j];
			}
		}
		
		while (!q.empty()) { // 확산 
			int ypos = q.front().first;
			int xpos = q.front().second;
			q.pop();
			
			int temp = copy[ypos][xpos] / 5;
			
			for (int i=0; i<4; i++) {
				int nextY = ypos + y[i];
				int nextX = xpos + x[i];
				
				if(0 > nextX || 0 > nextY || nextY == r || nextX == c) continue;
				
				if(copy[nextY][nextX] >= 0) { // 영향 안 주기위함 
					arr[nextY][nextX] += temp;
					arr[ypos][xpos] -= temp;
				}
			}
		}
		
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				copy[i][j] = arr[i][j];
			}
		} 
		
		int ypos = air_top.first;
		int xpos = air_top.second+1;
		arr[ypos][xpos] = 0;
		
		for (int i=0; i<4; i++) {
			while(1) {
				int nextY = ypos + y[ccw[i]];
				int nextX = xpos + x[ccw[i]];
				
				if(nextY == air_top.first && nextX == air_top.second) break;
				if(0 > nextY || 0 > nextX || nextY == r || nextX == c) break;
				
				arr[nextY][nextX] = copy[ypos][xpos];
				ypos = nextY;
				xpos = nextX;
			}
		}
		
		ypos = air_bot.first;
		xpos = air_bot.second+1;
		arr[ypos][xpos] = 0;
		
		for (int i=0; i<4; i++) {
			while(1) {
				int nextY = ypos + y[cw[i]];
				int nextX = xpos + x[cw[i]];
				
				if(nextY == air_bot.first && nextX == air_bot.second) break;
				if(0 > nextY || 0 > nextX || nextY == r || nextX == c) break;
				
				arr[nextY][nextX] = copy[ypos][xpos];
				ypos = nextY;
				xpos = nextX;
			}
		}
	}
	int ans = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if(arr[i][j] > 0)
				ans += arr[i][j];
		}
	}
	cout << ans;
} 

