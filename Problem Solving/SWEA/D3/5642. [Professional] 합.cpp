#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		int best = v[0], sum = 0;
		for (int i=0; i<n; i++) {
			if(sum + v[i] < v[i]) sum = v[i];
			else sum += v[i];
			best = max(best,sum);
		}
		cout << "#" << t << ' ' << best << '\n';
	}
}
