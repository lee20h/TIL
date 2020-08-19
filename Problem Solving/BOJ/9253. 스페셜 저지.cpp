#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t, r;
	cin >> s >> t >> r;
	if(s.find(r) != string::npos && t.find(r) != string::npos)
		cout << "YES";
	else
		cout << "NO";
}
