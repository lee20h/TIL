#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int ans;
int n, c;

bool possible(int dist) {
	int cnt = 1;
	int low = v[0];
	
	for (int i=1; i<n; i++) {
		if(v[i] - low >= dist) {
			cnt++;
			low = v[i];
		}
	}
	if(cnt >= c) {
		return true;
	}
	else
		return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	
	int left = 1;
	int right = v[n-1] - v[0];
	
	while(left <= right) {
		int mid = (left + right) / 2;
		if(possible(mid)) {
			ans = max(ans,mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans; 
}
