#include <bits/stdc++.h>
using namespace std;

int main() {
	int d, v;
	vector<pair<int,int>> vec;
	for (int i=0; i<11; i++) {
		cin >> d >> v;
		vec.push_back({d,v});
	}
	sort(vec.begin(),vec.end());
	
	int ans = 0;
	int t = 0;
	for (int i=0; i<11; i++) {
		t += vec[i].first;
		ans += t + vec[i].second * 20;
	}
	cout << ans;
}
