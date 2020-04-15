#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	int tc;
	cin >> tc;
	int len;
	for (int t=1; t<=tc; t++) {
		cin >> len;
		cin >> a >> b;
		int cnt = 0;
		
		for (int i=0; i<len; i++) {
			if(a[i] == b[i]) cnt++;
		}
		cout << "#" << t << ' ' << cnt << '\n';
	}
}
