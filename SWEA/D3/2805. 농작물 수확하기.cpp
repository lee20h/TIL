#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		cin >> n;
		vector<int> v[n];
		for(int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				char temp;
				cin >> temp;
				v[i].push_back(temp - '0');
			}
		}
		
		int sum = 0;
		for (int i=0; i<=n/2; i++) {
			for (int j=n/2-i; j<=n/2+i; j++) {
				sum += v[i][j];
			}
		}
		
		int idx = n/2-1;
		for (int i=n/2+1; i<n; i++) {
			for (int j=n/2-idx; j<=n/2+idx; j++) {
				sum += v[i][j];
			}
			idx--;
		}
		cout << "#" << t << ' ' << sum << '\n';
	}
}
