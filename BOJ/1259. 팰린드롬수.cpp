#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	while(str!="0") {
		cin >> str;
		bool flag = false;
		if(str=="0")
			break;
		for (int i=0; i<str.length(); i++) {
			if(str[i]!=str[str.size()-1-i]) {
				cout << "no\n";
				flag = true;
				break;
			}
		}
		if(!flag)
		cout << "yes\n";
	}
}
