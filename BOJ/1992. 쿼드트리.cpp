#include <iostream>
using namespace std;

char data[64][64];

void sol(int size, int y, int x) {
	bool flag = false;
	char temp = data[y][x];
	for (int i=y; i<y+size; i++) {
		for (int j=x; j<x+size; j++) {
			if(data[i][j] != temp) 
				flag = true;
		}
	}
	
	if(flag) {
		cout << "(";
		sol(size/2,y,x);
		sol(size/2,y,x+size/2);
		sol(size/2,y+size/2,x);
		sol(size/2,y+size/2,x+size/2);
		cout << ")";
	}
	else {
		cout << temp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char temp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> temp;
			data[i][j] = temp;
		}
	}
	sol(n,0,0);
	
}
