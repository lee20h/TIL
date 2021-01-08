#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<long long> v;
	int n;
	cin >> n;
	
	for (int i=1; i<=1023; i++) {
		long long num = 0;
		int temp = i;
		for (int idx=9; idx>=0; idx--) {
			if(temp&1)
				num = 10*num + idx;
			temp /= 2;
		}
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	if(n > 1022)
		cout << "-1";
	else
		cout << v[n];
}
