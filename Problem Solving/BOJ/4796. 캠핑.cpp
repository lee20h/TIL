#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, p, v;
	int cnt = 1;
	while(1) {
		cin >> l >> p >> v;
		if(l == 0 && p == 0 && v == 0) break;
		int ans = v / p * l;
		int temp = v % p;
		temp > l ? ans += l : ans += temp;
		cout << "Case " << cnt << ": " << ans << '\n';
		cnt++;
	}
}
