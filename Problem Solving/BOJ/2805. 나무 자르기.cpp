#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector<int> v;
	cin >> n >> m;
	long long temp;
	long long right = 0;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
		right = max(right,temp);
	}
	
	long long left = 0;
	long long ans = 0;
	while(left<=right) {
		long long sum = 0;
		long long mid = (left + right) / 2;
		for (int i=0; i<n; i++) {
			if(mid < v[i])
				sum += v[i] - mid;
		}
		if(sum >= m) {
			ans = max(ans,mid);
			left = mid +1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}
