#include <bits/stdc++.h>
using namespace std;

char v[100][100];

int x(int len, int pos_y, int pos_x) {
	for (int i=0; i<len/2; i++) {
		if(v[pos_y][pos_x + i] != v[pos_y][pos_x + len - 1 - i])
			return 0;
	}
	return len;
}
int y(int len, int pos_y, int pos_x) {
	for (int i=0; i<len/2; i++) {
		if(v[pos_y + i][pos_x] != v[pos_y + len - 1 - i][pos_x])
			return 0;
	}
	return len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int t=1; t<=10; t++) {
		int temp, len = 0;
		cin >> temp;
		for (int i=0; i<100; i++) {
			for (int j=0; j<100; j++) {
				cin >> v[i][j];
			}
		}
		
		for (int k=1; k<100; k++) {
			for (int i=0; i<=100-k; i++) {
				for (int j=0; j<100; j++) {
					temp = y(k,i,j);
					len = max(len,temp);
				}
			}
			for (int i=0; i<100; i++) {
				for (int j=0; j<=100-k; j++) {
					temp = x(k,i,j);
					len = max(len,temp);
				}
			}
		}
		cout << "#" << t << ' ' << len << '\n';
	}
}
