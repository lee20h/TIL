#include <bits/stdc++.h>
using namespace std;

const int MAX = 300000;
long long arr[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long right = 0;
	long long left = 1;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}
	
	long long ans = LLONG_MAX;
	while(left<=right) {
		long long mid = (left + right) / 2;
		long long temp = 0;
		for (int i=0; i<m; i++) {
			temp += arr[i] / mid;
			if(arr[i] % mid) temp++;
		}
		
		if(n >= temp) {
			ans = min(ans,mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		
	}
	cout << ans;
}
