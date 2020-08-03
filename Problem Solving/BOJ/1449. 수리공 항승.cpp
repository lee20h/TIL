#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	vector<int> v;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	
	int prev = v[0] + l - 1;
	int ans = 1;
	for (int i=1; i<n; i++) {
		if(prev >= v[i]) {
			continue;
		}
		else {
			prev = v[i] + l - 1;
			ans++;
		}
	}
	cout << ans;
}
