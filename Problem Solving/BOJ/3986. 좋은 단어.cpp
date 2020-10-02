#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		stack<char> st;
		string s;
		cin >> s;
		for (int j=0; j<s.length(); j++) {
			if(!st.empty() && st.top() == s[j]) {
				st.pop();
			}
			else st.push(s[j]);
		}
		if(st.empty())
			ans++;
	}
	cout << ans;
} 
