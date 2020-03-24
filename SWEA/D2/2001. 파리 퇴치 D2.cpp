#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, m;
	int t;
	cin >> t;
	int sum=0;
	int max_sum=0;
	int garo=0, sero=0;
	int fly[15][15];
	for (int test=1; test<=t; test++) {
		
		cin >> n >> m;
		garo=0;
		sero=0;
		max_sum=0;
		sum=0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> fly[i][j];
			}
		}
		while(1) {
			for (int i=sero; i<m+sero; i++) {
				for(int j=garo; j<m+garo; j++) {
					sum += fly[i][j];
				}
			}
			max_sum = max(sum,max_sum);
			sum=0;
			
			if(sero+m < n || garo+m < n) {
				if(garo+m < n)
					garo++;
				else{
					sero++;
					garo=0;
				}
			}
			else 
				break;
		}
		
		cout << "#" << test << ' ' << max_sum << '\n';
	}
}
