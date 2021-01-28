#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

int py[4] = {0, 0, 1, -1};
int px[4] = {1, -1, 0, 0};

int n;
double prob[4], ans;
bool visited[MAX][MAX];


void dfs(int y, int x, double chance) {
	if(n == 0) {
		ans += chance;
		return;
	}
	
	visited[y][x] = true;
	for (int i=0; i<4; i++) {
		int dy = y + py[i];
		int dx = x + px[i];
		
		if(!visited[dy][dx]) {
			n--;
			dfs(dy, dx, chance * prob[i]);
			visited[dy][dx] = false;
			n++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cin >> n;
	
	for (int i=0; i<4; i++) {
		cin >> prob[i];
		prob[i] *= 0.01;
	}
	dfs(15, 15, 1.0);
	cout << ans;
}
