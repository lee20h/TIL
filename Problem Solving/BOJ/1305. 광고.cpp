#include <bits/stdc++.h>
using namespace std;

string t, p;

vector<int> getPartialMatch(string str) {
	int m = str.size();
	vector<int> pi(m,0);
	int begin = 1, matched = 0;
	
	while(begin + matched < m) {
		if (str[begin + matched] == str[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if(matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l;
	string str;
	cin >> l;
	cin >> str;
	vector<int> pi = getPartialMatch(str);
	
	cout << l - pi[l-1];
}
