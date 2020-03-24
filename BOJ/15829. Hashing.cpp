#include <iostream>
#include <cmath>
using namespace std;


int main() {
	string str;
	int num;
	cin >> num;
	cin >> str;
	
	long long M = 1234567891;
	long long R = 1;
	
	unsigned long long sum = 0;
	for (int i=0; i<num; i++) {
		sum += (str[i] - 'a' + 1) * R;
		sum %= M;
		R *= 31;
		R %= M;
	}
	cout << sum;
}
