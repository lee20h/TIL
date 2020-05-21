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
	int best = v[0], sum = 0;
	for (int i=0; i<n; i++) {
		if(sum < 0) sum = v[i];
		else sum += v[i];
		best = max(best,sum);
	}
	cout << best;
}
