#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int ans = 0;
	
	cin >> s;
	
	sort(s.begin(), s.end());
	
	do {
		bool flag = false;
		for(int i=1; i<s.size(); i++) {
			if(s[i-1] == s[i]) {
				flag = true;
				break;
			}
		}
		if(!flag)
			ans++;
	} while(next_permutation(s.begin(), s.end()));
	
	cout << ans;
	
	
}
