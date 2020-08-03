#include <bits/stdc++.h>
using namespace std;

int money[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int sum = k;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		cin >> money[i];
	}
	
	while(sum!=0) {
		for (int i=n-1; i>=0; i--) {
			if(sum>=money[i]) {
				sum -= money[i];
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
