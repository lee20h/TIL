#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int> &v, int dist) {
	int cnt = 0;
	for (int i=1; i<v.size(); i++) {
		cnt += (v[i] - v[i-1] - 1) / dist;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v = {0, l};
	
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	
	int right = l;
	int left = 0;
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(getMinDistance(v, mid) > m)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;
}
