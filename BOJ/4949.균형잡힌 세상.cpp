#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<char> s;
	string str;
	bool flag;
	while(1) {
		getline(cin, str);
		if(str==".")
			break;	
		
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
		
		if(!flag && s.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}	
	
			
}
	
