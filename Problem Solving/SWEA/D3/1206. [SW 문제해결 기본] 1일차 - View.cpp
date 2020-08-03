#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int t=1; t<=10; t++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		int ans = 0;
		for (int i=2; i<n-2; i++) {
			bool flag = false;
			int temp[4];
			int min_build = 300;
			temp[0] = v[i] - v[i-2];
			temp[1] = v[i] - v[i-1];
			temp[2] = v[i] - v[i+1];
			temp[3] = v[i] - v[i+2];
			for (int j=0; j<4; j++) {
				if(temp[j] <= 0) {
					flag = true;
					break;	
				}
				min_build = min(temp[j],min_build);
			}
			if(flag) continue;
			ans += min_build;
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
