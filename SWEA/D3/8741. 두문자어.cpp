#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	
	for (int t=1; t<=testcase; t++) {
		string str[3];
		string ans;
		for (int i=0; i<3; i++) {
			cin >> str[i];
			ans += toupper(str[i].front());
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
