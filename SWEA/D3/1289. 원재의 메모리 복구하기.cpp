#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		string str;
		cin >> str;
		int ans = 0;
		if (str[0] - '0' == 1) ans++;
		
		for (int i=1; i<str.size(); i++) {
			if(str[i-1] == str[i]) continue;
			else ans++;
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
