#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<char> s;
	string str;
	bool flag;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> str;
		flag = false;
		while(!s.empty())
			s.pop();
		for (int i=0; i<str.length(); i++) {
			
			if(str[i]=='(')
				s.push(str[i]);
			else if(str[i]=='[')
				s.push(str[i]);
				
			else if(str[i]==')') {
				if(!s.empty() && s.top()=='(') {
					s.pop();
				}
					
				else {
					flag = true;
					break;
				}
			}
			else if(str[i]==']') {
				if(!s.empty() && s.top()=='['){
					s.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}	
		if(!flag && s.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

	
