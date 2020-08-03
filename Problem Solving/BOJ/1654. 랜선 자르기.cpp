#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int v[10000];

bool cut(int mid) {
	int cnt = 0;
	for(int i=0; i<k; i++)
		cnt += v[i] / mid;
	return cnt >= n;
}


int main() {
	
	cin >> k >> n;
	int high = 0;
	for (int i=0; i<k; i++) {
		cin >> v[i];
		high = max(high,v[i]);
	}
	long long left = 1, right = high;
	int ans = 0;
	while(left <= right) {
		long long mid = (left+right) / 2;
		if(cut(mid)) {
			if(mid > ans)
				ans = mid;
			left = mid+1;
		}
		else right = mid-1;
	}
	cout << ans;
}
