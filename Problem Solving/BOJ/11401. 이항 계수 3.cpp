#include <bits/stdc++.h>
using namespace std;

#define P 1000000007
#define ll long long
ll fac[4000001], n, k, inv[4000001];
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
	for (int i = 2; i <= 4000000; i++)
		fac[i] = (fac[i-1] * i) % P;
	inv[4000000] = power(fac[4000000], P - 2);
	for (int i=4000000-1; i>0; i--)
		inv[i] = (inv[i+1] * (i+1)) % P;
	
	
	int n, r;
	cin >> n >> r;
	
	if (n == r || !r) {
		cout << "1";
		return 0;
	}
	
	ll ans = (fac[n] * inv[n-r]) % P;
	ans = (ans*inv[r] % P);
	cout << ans; 
}
