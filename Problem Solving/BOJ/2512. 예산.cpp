#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int sum = 0;
	int right = 0;
	int left = 0;
	int ans = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		right = max(right,temp);
	}
	cin >> m;
	sort(v.begin(),v.end());
	if(sum <= m) {
		cout << v[n-1];
		return 0;
	}
	
	while(left<=right) {
		sum = 0;
		int mid = (left + right) / 2;
		for (int i=0; i<n; i++) {
			if(mid < v[i])
				sum += mid;
			else sum += v[i];
		}
		
		if(sum <= m) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}
