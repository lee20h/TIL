#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	
	int accum = 0;
	for (int i=0; i<n; i++) {
		if(accum + 1 < v[i]) {
			break;
		}
		accum += v[i];
	}
	cout << accum + 1;
}
