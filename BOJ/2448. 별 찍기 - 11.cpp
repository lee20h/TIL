#include <iostream>
using namespace std;

char arr[3072][6144];

void star(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y+1][x-1] = '*';
		arr[y+1][x+1] = '*';
		arr[y+2][x-2] = '*';
		arr[y+2][x-1] = '*';
		arr[y+2][x] = '*';
		arr[y+2][x+1] = '*';
		arr[y+2][x+2] = '*';
		return;
	}
	
	star(n/2,y,x);
	star(n/2,y+(n/2),x-(n/2));
	star(n/2,y+(n/2),x+(n/2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; 
	for (int i=0; i<n; i++) {
		for (int j=0; j<2*n; j++) {
			if (j == 2 * n - 1)
				arr[i][j] = '\0';
			else
				arr[i][j] = ' ';
		}
	}
	
	star(n, 0, n-1);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<2*n-1; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
