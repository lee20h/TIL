#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> st;
	string s;
	cin >> s;
    int ans = 0;
    int temp = 1;
    
    for (int i=0; i<s.length(); i++) {
    	if (s[i] == '(') {
    		temp *= 2;
    		st.push(s[i]);
    		if(i+1 < s.length() && s[i+1] == ')') ans += temp;
		}
		else if (s[i] == '[') {
			temp *= 3;
			st.push(s[i]);
			if(i+1 < s.length() && s[i+1] == ']') ans += temp;
		}
		else if (st.empty() && (s[i] == ')' || s[i] == ']')) {
			cout << "0";
			return 0;
		}
		if(!st.empty()) {
			if(s[i] == ')') {
				temp /= 2;
				if(st.top() == '(') st.pop();
			}
			else if(s[i] == ']') {
				temp /= 3;
				if(st.top() == '[') st.pop();
			}
		}
	}
	
	if(!st.empty()) cout << "0";
	else cout << ans;

}
