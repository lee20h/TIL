#include <bits/stdc++.h>
using namespace std;

int N, r, c, cnt;

void sol(int size, int y, int x) {
	if (size==2) {
		if(y == r && x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if(y == r&& x+1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if(y+1 == r&& x == c) {
			cout << cnt;
			return;
		}
		cnt++;
		if(y+1 == r&& x+1 == c) {
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}
	sol(size/2,y,x);
	sol(size/2,y,x+size/2);
	sol(size/2,y+size/2,x);
	sol(size/2,y+size/2,x+size/2);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> r >> c;
	sol(pow(2,N),0,0);
	
}
