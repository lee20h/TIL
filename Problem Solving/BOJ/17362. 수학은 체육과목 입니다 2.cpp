#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	n = n % 8;
	if (n==0) cout << "2";
	else if (n<=5) cout << n;
	else if(n==6) cout << "4";
	else if (n==7) cout << "3";
}
