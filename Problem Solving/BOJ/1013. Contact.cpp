#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	regex reg("(100+1+|01)+");
	cmatch m;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string str;
		cin >> str;
		bool flag = regex_match(str.c_str(), m, reg);
		flag ? cout << "YES\n" : cout << "NO\n";
	}
}
