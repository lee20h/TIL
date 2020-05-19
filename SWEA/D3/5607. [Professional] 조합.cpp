#include <bits/stdc++.h>
using namespace std;

#define P 1234567891
#define ll long long
ll fac[1000001], n, k, inv[1000001];
ll power(ll x, ll y) {
	ll result = 1;
	while(y) {
		if (y%2) {
			result *= x;
			result %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return result;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	fac[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		fac[i] = (fac[i-1] * i) % P;
	inv[1000000] = power(fac[1000000], P - 2);
	for (int i=1000000-1; i>0; i--) {
		inv[i] = (inv[i+1] * (i+1)) % P;
	}
	
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n, r;
		cin >> n >> r;
		
		if (n == r || !r) {
			cout << "1";
			return 0;
		}
		
		ll ans = (fac[n] * inv[n-r]) % P;
		ans = (ans*inv[r] % P);
		cout << "#" << t << ' ' << ans << '\n';
	}
}
