#include<iostream>
using namespace std;

int main() {
	string str;
	int t;
	string sub;
	string sub2;
	int madi;
	cin >> t;
	for (int i=1; i<=t; i++) {
		cin >> str;
		for (madi=1; madi<str.length(); madi++) {
			sub = str.substr(0,madi);
			sub2 = str.substr(madi,madi);
			if (sub == sub2) {
				break;
			}
		}
		
		cout << "#" << i << ' ' << madi << '\n';
	}
	
}
