#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> v; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, d;
	int a, b, c;
	cin >> n >> k >> d;
	for (int i=0; i<k; i++) {
		cin >> a >> b >> c;
		v.push_back({{a,b},c});
	}
	
	int left = 1;
	int right = n;
	int ans = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		
		long long sum = 0;
		for (int i=0; i<k; i++) {
			int high = min(v[i].first.second, mid);
			if(high >= v[i].first.first) {
				sum += ((high - v[i].first.first) / v[i].second) + 1;
			}
		}
		if(sum >= d) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
	
}
