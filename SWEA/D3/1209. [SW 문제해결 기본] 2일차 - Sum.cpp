#include <bits/stdc++.h>
using namespace std;

int v[100][100];
int max_sum = 0;
void sum1() {
	for (int i=0; i<100; i++) {
		int sum1 = 0, sum2 = 0;
		for (int j=0; j<100; j++) {
			sum1 += v[i][j];
			sum2 += v[j][i];
		}
		int temp = max(sum1,sum2);
		max_sum = max(temp, max_sum);
	}
}
void sum2(){
	int sum1 = 0, sum2 = 0;
	for (int i=0; i<100; i++) {
		sum1 += v[i][i];
		sum2 += v[i][99-i];
	}
	int temp = max(sum1,sum2);
	max_sum = max(temp, max_sum);
}

int main() {
	
	for (int t=1; t<=10; t++) {
		int n;
		cin >> n;
		max_sum = 0;
		for (int i=0; i<100; i++) {
			for (int j=0; j<100; j++) {
				cin >> v[i][j];
			}
		}
		sum1();
		sum2();
		cout << "#" << t << ' ' << max_sum << '\n';
	}
	
}
