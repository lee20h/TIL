#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
long long v[MAX], temp[MAX];

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	sort(v,v+n);
	
	int ans = 0;
	
	if(n&1) {
		ans = n/2;
		int idx = n-1;
		for (int i=n-1; i>=0; i-=2)
			temp[i] = v[idx--];
		idx = 0;
		for (int i=1; i<n; i+=2)
			temp[i] = v[idx++];
	}
	else {
		ans = n/2-1;
		int idx = n-3;
		temp[0] = v[n-2];
		temp[n-1] = v[n-1];
		for (int i=n-2; i>1; i-=2)
			temp[i] = v[idx--];
		idx = 0;
		for (int i=1; i<n-2; i+=2)
			temp[i] = v[idx++];
	}
	cout << ans << '\n';
	for (int i=0; i<n; i++)
		cout << temp[i] << ' ';
}
