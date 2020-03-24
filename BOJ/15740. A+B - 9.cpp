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
	int borrow = 0;
	bool x, y;
	if(a[0]=='-') {
		x = true;
		a= a.substr(1,a.size()-1);
	}
	if(b[0]=='-') {
		y = true;
		b = b.substr(1,b.size()-1);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	while (a.length() < b.length()) {
		a += '0';
	}
	while (a.length() > b.length()) {
		b += '0';
	}
	
	
	if(!x && !y) {
		for (int i=0; i<a.length(); ++i) {
			num = (a[i] - '0' + b[i] - '0' + carry) % 10;
			ans += to_string(num);
			carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
		}
		if (carry != 0)
			ans += to_string(carry);
	}
	else if(x && y) {
		for (int i=0; i<a.length(); ++i) {
			num = (a[i] - '0' + b[i] - '0' + carry) % 10;
			ans += to_string(num);
			carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
		}
		if (carry != 0)
			ans += to_string(carry);
		ans += '-';
	}
	else {
		for (int i=0; i<a.length(); i++) {
			if(x) {
				num = (b[i] - '0') - (a[i] - '0') - borrow;
			}
			else {
				num = (a[i] - '0') - (b[i] - '0') - borrow;
			}
			borrow = 0;
			if (num <0) {
				borrow = 1;
				num += 10;
			}
			ans += to_string(num);
		}
		
		
	}
	
	reverse(ans.begin(),ans.end());
	int z = ans.length()-1;
		int cnt = 0;
		while(z>=0) {
			if(ans[z] == '0') {
				cnt++;
				z--;
				continue;
			}
			break;
		}
		ans = ans.substr(0,ans.size()-z);
	cout << ans;
}
