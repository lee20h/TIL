#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n, temp;
		vector<int> v;
		cin >> n;
		
		for (int i=0; i<n; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		sort(v.begin(),v.end());
		int sum = 0;
		for (int i=0; i<v.size(); i++) {
			sum += v[i];
		}
		sum += v[v.size()-1] + v.size();
		
		cout << "#" << t << ' ' << sum << '\n';
	}
}
