#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string str;
	int dec = 0;
	cin >> str;
	int sum=0;
	for (int i=0; i<str.size(); i++) {
		
		if ('A' <= str[i] && str[i] <= 'F') {
			sum += (str[i] - 55) * (pow(16,str.size()-1-i));
		}
		else {
			sum += (int)(str[i]-48) * (pow(16,str.size()-1-i));
		}
	}
	cout << sum;
}
