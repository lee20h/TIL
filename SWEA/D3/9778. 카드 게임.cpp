#include <bits/stdc++.h>
using namespace std;

int card[12];

int main() {
	int tc;
	cin >> tc;
	
	for (int t=1; t<=tc; t++) {
		for (int i=2; i<=11; i++) {
			card[i] = 4;
			if(i==10) card[i] = 16;
		}
		int n, temp;
		int sum = 0;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> temp;
			card[temp]--;
			sum += temp;
		}
		
		int ans = 21 - sum;
		int a, b;
		a = b = 0;
		for (int i=2; i<=ans; i++) {
			a += card[i];
		}
		for (int i=11; i>ans; i--) {
			b += card[i];
		}
		
		if (a > b) {
			cout << "#" << t << ' ' << "GAZUA" << '\n';
		}
		else {
			cout << "#" << t << ' ' << "STOP" << '\n';
		}
	}
}
