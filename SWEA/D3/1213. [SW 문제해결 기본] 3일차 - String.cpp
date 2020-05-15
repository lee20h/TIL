#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int t=1; t<=10; t++) {
		string str;
		string word;
		int n;
		cin >> n >> word >> str;
		int cnt = 0;
		
		for (int i=0; i<str.length(); i++) {
			string temp = str.substr(i,word.length());
			if (temp == word) cnt++;
		}
		cout << "#" << t << ' ' << cnt << '\n';
	}
	
}
