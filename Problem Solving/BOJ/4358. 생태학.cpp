#include <bits/stdc++.h>
using namespace std;

map<string, double> m;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cout << fixed;
	cout.precision(4);
	
	while(getline(cin,str)) {
		if(!str.length())
			break;
		cnt++;
		m[str]++;
	}
	
	for(auto i : m) {
		cout << i.first << " " << i.second/cnt * 100 << '\n'; 
	}
	
}
