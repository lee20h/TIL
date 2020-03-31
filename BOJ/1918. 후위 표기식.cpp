#include <bits/stdc++.h>
using namespace std;

int precedence(char a) {
	switch(a) {
		case '(' : case ')' : return 0;
		case '+' : case '-' : return 1;
		case '*' : case '/' : return 2;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	char op;
	stack<char> st;
	for (int i=0; i<str.length(); i++) {
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			while(!st.empty()) {
				op = st.top();
				if(precedence(str[i]) <= precedence(op)) {
					cout << op;
					st.pop();
				}
				else break;
			}
			st.push(str[i]);
		}
		else if(str[i] == '(') st.push(str[i]);
		else if(str[i] == ')'){
			while(!st.empty()) {
				op = st.top();
				st.pop();
				if(op == '(') break;
				else cout << op;
			}
		}
		else {
			cout << str[i];
		}
	}
	
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
