#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int,int>> v;
	int n, ans = 0;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({s,e});
	}
	
	sort(v.begin(), v.end());
	
	int start = v[0].first;
	int end = v[0].second;
	
	for(int i=1; i<v.size(); i++) {
		if(v[i].first > end) {
			ans += end - start;
			start = v[i].first;
			end = v[i].second;
		}
		else if(v[i].first < end && end < v[i].second)
			end = v[i].second;
	}
	ans += end - start;
	
	cout << ans;
}
