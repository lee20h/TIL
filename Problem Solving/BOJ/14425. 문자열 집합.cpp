#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, bool> str;
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		str[s] = true;
	}
	
	for (int i=0; i<m; i++) {
		string s;
		cin >> s;
		if(str[s])
			cnt++;
	}
	cout << cnt;
}
