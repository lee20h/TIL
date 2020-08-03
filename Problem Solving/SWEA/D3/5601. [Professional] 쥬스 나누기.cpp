#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		cin >> n;
		
		cout << "#" << t << ' ';
		for (int i=0; i<n; i++) {
			cout << "1/" << n << ' ';
		}
		cout << '\n';
	}
}
