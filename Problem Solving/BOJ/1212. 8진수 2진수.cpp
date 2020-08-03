#include <iostream>
#include <bitset>
using namespace std;

int main() {
	string num;
	cin >> num;
	bitset<3> bit(num[0] - '0');
	
	if(num[0]-'0'>=4) {
		cout << bit;
	}
	else if(num[0] - '0' <= 1) {
		bitset<1> bit(num[0] - '0');
		cout << bit;
	}
	else {
		bitset<2> bit(num[0] - '0');
		cout << bit;
	}
	
	for (int i=1; i<num.length(); i++) {
		bitset<3> bit(num[i] - '0');
		cout << bit;
	}
	
}
