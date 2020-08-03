#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		vector<int> v;
		cin >> n;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		bool chk = true;
		for (int i=1; i<n; i++) {
			if(v[i-1] == v[i])
				chk = false;
		}
		cout << "#" << t << ' ';
		if(chk)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
		
	}
}
