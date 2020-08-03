#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	for (int i=0; i<str.length(); i++) {
		cout << (int)str[i] - 64 << ' ';
	}
	return 0;
}
