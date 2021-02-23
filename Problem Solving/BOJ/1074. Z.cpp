#include <bits/stdc++.h>
using namespace std;

int N, r, c, cnt;

void sol(int size, int y, int x) {
    if(y == r && x == c) {
        cout << cnt;
        return;
    }
    if(size == 1) {
        cnt++;
        return;
    }
    if(y > r || r >= y+size || x > c || c >= x+size) {
        cnt += size * size;
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
