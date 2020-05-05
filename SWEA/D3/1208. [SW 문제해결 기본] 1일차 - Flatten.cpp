#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int t=1; t<=10; t++) {
		int dump;
		cin >> dump;
		vector<int> v(100);
		for (int i=0; i<100; i++) {
			cin >> v[i];
		}
		while(dump--) {
			int max_idx = max_element(v.begin(),v.end()) - v.begin();
			int min_idx = min_element(v.begin(),v.end()) - v.begin();
			v[max_idx]--;
			v[min_idx]++;
		}
		int max_idx = max_element(v.begin(),v.end()) - v.begin();
		int min_idx = min_element(v.begin(),v.end()) - v.begin();
		int ans = v[max_idx] - v[min_idx];
		cout << "#" << t << ' ' << ans << '\n';
	}
}
