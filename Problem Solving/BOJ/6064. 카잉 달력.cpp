#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int x, y;
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cin >> m >> n >> x >> y;
		int base = lcm(m,n);
		while(1) {
			if(x > base || (x-1) % n+1 == y)
				break;
			x += m;
		}
		if(x > base) cout << "-1" << '\n';
		else cout << x << '\n';
	}
}
