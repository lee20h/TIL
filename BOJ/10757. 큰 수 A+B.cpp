#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a,b;
	string ans = "";
	cin >> a >> b;
	int num;
	int carry = 0;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	while (a.length() < b.length()) {
		a += '0';
	}
	while (a.length() > b.length()) {
		b += '0';
	}
	
	for (int i=0; i<a.length(); ++i) {
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		ans += to_string(num);
		carry = (a[i] - '0' + b[i] - '0'+carry) / 10;
	}
	if (carry != 0)
		ans += to_string(carry);
	reverse(ans.begin(),ans.end());
	cout << ans;
}
