#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, size = 0;
	cin >> n;
	vector<int> v(n), num, ans(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
		size = max(size, v[i]);
	}
	num.resize(size+1);
	for (int i=0; i<n; i++)
		num[v[i]]++;
		
	for (int i=0; i<n; i++) {
		for (int j=1; j*j<=v[i]; j++) {
			if(v[i] % j == 0) {
				if(v[i] / j != j)
					ans[i] += num[v[i]/j];
				ans[i] += num[j];
			}
		}
	}
	for (int i=0; i<n; i++)
		cout << ans[i]-1 << '\n';
}
