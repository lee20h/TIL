#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;
	
	for (int t=1; t<=test; t++) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		int ans = 0;
		int people = 0;
		int v[20];
		for (int i=0; i<n; i++) {
			sum = 0;
			for (int j=0; j<m; j++) {
				int temp;
				cin >> temp;
				sum += temp;
			}
			v[i] = sum;
			if(sum > ans) {
				ans = sum;
			}
		}
		
		for (int i=0; i<n; i++) {
			if(v[i] == ans)
				people++;
		}
		cout << "#" << t << ' ' << people << ' ' << ans << '\n';
	}
}
