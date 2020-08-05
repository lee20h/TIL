#include <bits/stdc++.h>
using namespace std;

vector<bitset<26>> check;
vector<bitset<26>> copy_check;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	check.resize(n);
	string str;
	for (int i=0; i<n; i++) {
		cin >> str;
		for (int j=0; j<str.size(); j++) {
			check[i][str[j] - 'a'] = true;
		}
	}
	
	copy_check = check;
	
	for (int i=0; i<m; i++) {
		int cmd, cnt = 0;
		char x;
		cin >> cmd >> x;
		
		if(cmd == 1) {
			for (int j=0; j<n; j++) {
				if(copy_check[j][x - 'a'] == true)
					check[j][x - 'a'] = false;
			}
		}
		
		else {
			for (int j=0; j<n; j++) {
				if(copy_check[j][x - 'a'] == true)
					check[j][x - 'a'] = true;
			}
		}
		
		for (int j=0; j<n; j++) {
			if(copy_check[j] == check[j]) cnt++;
		}
		cout << cnt << '\n';
		
	}
}
