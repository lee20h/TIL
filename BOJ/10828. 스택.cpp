#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> st;
	int n;
	string str;
	cin >> n;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> str;
		if(str=="push") {
			cin >> temp;
			st.push(temp);
		}
		else if(str=="pop") {
			if(st.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if(str=="size") {
			cout << st.size() << '\n';
		}
		else if(str=="empty") {
			if(st.empty())
				cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if(str=="top") {
			if(st.empty())
				cout << "-1" << '\n';
			else {
				cout << st.top() << '\n';
			}
		}
		
	}
}
