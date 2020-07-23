#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<long long,long long>> v;
	long long l, n, J, B, x, c;
	cin >> l >> n >> J >> B;
	for (int i=0; i<n; i++) {
		cin >> x >> c;
		v.push_back({x,c});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	long long cur = 0, res = 0;
	for (int i=0; i<v.size(); i++) {
		if(cur < v[i].second) {
			res += (J - B) * (v[i].second - cur) * v[i].first;
			cur = v[i].second;
		}
	}
	cout << res;
} 
