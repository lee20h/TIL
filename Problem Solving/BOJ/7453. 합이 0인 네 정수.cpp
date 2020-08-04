#include <bits/stdc++.h>
using namespace std;

const int MAX = 4000;

vector<long long> v;
int arr[4][MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<4; j++) {
			cin >> arr[j][i];
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}
	
	sort(v.begin(),v.end());
	
	
	long long ans = 0;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			long long ab = arr[0][i] + arr[1][j];
			
			long long first = lower_bound(v.begin(),v.end(), -ab) - v.begin();
			long long last = upper_bound(v.begin(),v.end(), -ab) - v.begin();
			
			if(v[first] == -ab) {
				ans += (last - first);
			}
		}
	}
	
	cout << ans;
	
}
