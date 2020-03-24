#include <iostream>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	map<string,int> b;
	vector<string> v;
	string str;
	cin >> n >> m;
	v.push_back("0");
	b.insert(make_pair("0",0));
	for (int i=1; i<=n; i++) {
		cin >> str;
		b.insert(make_pair(str,i));
		v.push_back(str);
	}
	
	for (int i=1; i<=m; i++) {
		cin >> str;
		if(isdigit(str[0])) {
			cout << v[stoi(str)] << '\n';
		}
		else {
			cout << b[str] << '\n';
		}
	}
	
}
