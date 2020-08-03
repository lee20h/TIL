#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	if(a.length() == 4)
		cout << "20";
	else if(a.length() == 3) {
		if(a[1]=='0') {
			cout << (int)a[2] - '0' + 10;
		}
		else if(a[2]=='0') {
			cout << (int)a[0] - '0' + 10;
		}
	}
	else if(a.length() == 2) {
		cout << (int)a[0] - '0' + (int)a[1] - '0';
	}
}
