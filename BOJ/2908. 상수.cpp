#include <iostream>
using namespace std;

int main() {
	int a, b;
	int ra=0,rb=0;
	cin >> a >> b;
	ra = ((a%10)*100)+ (((a/10)%10)*10)+ (a/100);
	rb = (b%10) *100 + (b/10)%10 * 10 + b/100;
	if(a%10 > b%10) cout << ra;
	else if (a%10 < b%10) cout << rb;
	else {
		if ((a/10)%10 > (b/10)%10) cout << ra;
		else if ((a/10)%10 < (b/10)%10) cout << rb;
		else {
			a/100 > b/100 ? cout << ra : cout << rb;
		}
	}
}
