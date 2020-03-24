#include <iostream>
using namespace std;

int main() {
	char day;
	string number[5];
	cin >> day;
	int count = 0;
	for (int i=0; i<5; i++) {
		cin >> number[i];
		if(number[i][number[i].length()-1]==day) count++;
	}
	cout << count;
}
