#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int g, l, n;
	long long a, b;
	cin >> g >> l;
	
	int num = l / g; // a*b
	
	for (int i=1; i*i<=num; i++) {
		if(num%i == 0 && gcd(i, num/i) == 1) {
			n = i;
		}
	}
	 
	a = g * n;
	b = g * (num/n);
	cout << a << ' ' << b;
}
