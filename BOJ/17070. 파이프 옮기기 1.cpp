#include <bits/stdc++.h>
using namespace std;

int m[17][17];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> m[i][j];
		}
	}
	
	queue<pair<int,int>> fr;
	queue<pair<int,int>> ba;
	fr.push({1,1});
	ba.push({1,2});
	int answer = 0;
	
	while(!fr.empty() && !ba.empty()) {
		int fx = fr.front().second;
		int fy = fr.front().first;
		int bx = ba.front().second;
		int by = ba.front().first;
		fr.pop();
		ba.pop();
		if(bx == n && by == n) {
			answer++;
			continue;
		}
		if(fy == by && bx - fx == 1) { // 가로 
			if(bx < n && !m[by][bx+1]) {
				fr.push({by,bx});
				ba.push({by,bx+1});
			} 
			if(bx < n && by < n && !m[by+1][bx] && !m[by][bx+1] && !m[by+1][bx+1]) {
				fr.push({by,bx});
				ba.push({by+1,bx+1});
			}
		}
		else if(fx == bx && by - fy == 1) { // 세로 
			if(by < n && !m[by+1][bx]) {
				fr.push({by,bx});
				ba.push({by+1,bx});
			}
			if(bx < n && by < n && !m[by+1][bx] && !m[by][bx+1] && !m[by+1][bx+1]) {
				fr.push({by,bx});
				ba.push({by+1,bx+1});
			}
		}
		else if(bx - fx == 1 && by - fy == 1) {
			if(bx < n && !m[by][bx+1]) {
				fr.push({by,bx});
				ba.push({by,bx+1});
			}
			if(by < n && !m[by+1][bx]) {
				fr.push({by,bx});
				ba.push({by+1,bx});
			}
			if(bx < n && by < n && !m[by+1][bx] && !m[by][bx+1] && !m[by+1][bx+1]) {
				fr.push({by,bx});
				ba.push({by+1,bx+1});
			}
		}
	}
	cout << answer;
}
