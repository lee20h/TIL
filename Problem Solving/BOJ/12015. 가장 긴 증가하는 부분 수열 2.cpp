#include <bits/stdc++.h>
using namespace std;

vector<int> arr, dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	for (int i=0; i<n; i++) {
		vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), arr[i]);
		if(iter == dp.end()) dp.push_back(arr[i]);
		else *iter = arr[i];
	}
	cout << dp.size();
}
