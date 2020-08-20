#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int fail[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	while(1) {
		t++;
		int n;
		cin >> n;
		if(n == 0)
			break;
			
		string str;
		cin >> str;
		memset(fail, 0, sizeof(fail));
		
		for (int i=1, j=0; i<str.length(); i++) {
			while(j>0 && str[i] != str[j])
				j = fail[j-1];
			if(str[i] == str[j])
				fail[i] = ++j;
		}
		cout << "Test case #" << t << '\n'; 
		for (int i=2; i<=str.length(); i++) {
			if (fail[i-1] == 0 || fail[i - 1] % (i - fail[i - 1]))
				continue;
			int ans = i / (i - fail[i-1]);
			if(ans > 1) {
				cout << i << ' ' << ans << '\n';
			}
		}
		cout << '\n';
	}
} 
