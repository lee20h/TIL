#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int t;
	int count=0;
	cin >> t;
	int length;
	for (int test=1; test<=t; test++) {
		
		cin >> str;
		length = str.length();
		count=0;
		for (int i=0; i<length/2; i++) {
			if(str[i]==str[(length-1)-i])
				count++;
		}
		if (count == length/2) {
			cout << "#" << test << ' ' << "1" << '\n';
		}
		else {
			cout << "#" << test << ' ' << "0" << '\n';
		}
	}
}
