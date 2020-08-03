#include <iostream>
#include <string.h>
using namespace std;

bool check[50][50]= {false,};
int arr[50][50] = {0,};
int n, m;
int dir[4] = {1,0,-1,0};
int dir2[4] = {0,1,0,-1};
void search(int sero, int garo) {
	int x,y;
	for (int i=0; i<4; i++) {
		x = garo + dir2[i];
		y = sero + dir[i];
		
		if (x<0 || x>=m || y<0 || y>=n) continue;
		
		if(arr[y][x] && !check[y][x]) {
			check[y][x] = true;
			search(y,x);
		}
	}
}

int main() {
	int t;
	int a;
	int garo,sero;
	int insect;
	cin >> t;
	for (int test=0; test<t; test++) {
		cin >> m >> n >> a;
		memset(arr,0,sizeof(arr));
        memset(check,0,sizeof(check));
		insect = 0;
		for(int i=0; i<a; i++) {
			cin >> garo >> sero;
			arr[sero][garo] = 1;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if(arr[i][j] && !check[i][j]) {
					insect++;
					check[i][j] = true;
					search(i,j);
				}
			}
		}
		cout << insect << '\n';
	}
	
	return 0;
}
