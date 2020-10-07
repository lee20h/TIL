#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int d;
		string n;
		cin >> d >> n;
		int bOdd = 0, bEven = 0, rOdd = 0, rEven = 0;
		int e = 0;
		for (int i=0; i<d; i++) {
			if(i&1) {
				if((n[i] - '0') & 1)
					bOdd++;
				else
					bEven++;
			}
			else {
				if((n[i] - '0') & 1)
					rOdd++;
				else
					rEven++;
			}
		}
		if(d & 1) {
			if(rOdd > 0)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
		else {
			if(bEven > 0)
				cout << 2 << '\n';
			else
				cout << 1 << '\n';
		}
	}
}
