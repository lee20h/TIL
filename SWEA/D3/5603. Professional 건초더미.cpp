#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		cin >> n;
		int sum = 0;
		vector<int> v;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			sum += temp;
			v.push_back(temp);
		}
		int aver = sum / n;
		int ans = 0;
		for (int i=0; i<n; i++) {
			if(v[i] < aver) {
				ans += aver - v[i];
			}
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
