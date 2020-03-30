#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		int a, b;
		cin >> a >> b;
		int L = a * b / gcd(a,b);
		cout << L << '\n';
	}
}
