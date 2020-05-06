#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testcase;
	cin >> testcase;
	
	for (int t=1; t<=testcase; t++) {
		string str;
		cin >> str;
		vector<int> v[10];
		
		for (int i=0; i<str.size(); i++) {
			v[str[i] - '0'].push_back(1);
		}
		int ans = 0;
		
		for (int i=0; i<=9; i++) {
			if(v[i].size() % 2 == 1)
				ans++;
		}
		
		cout << "#" << t << ' ' << ans << '\n';
	}
}
