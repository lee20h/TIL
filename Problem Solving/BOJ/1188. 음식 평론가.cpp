#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m) {
	return m ? gcd(m, n%m) : n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m);
}
