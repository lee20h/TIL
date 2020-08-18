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

vector<int> kmp(string t, string p) {
	int n = t.size();
	int m = p.size();
	
	vector<int> result;
	vector<int> pi = getPartialMatch(p);
	int matched = 0;
	for (int i=0; i<n; i++) {
		while(matched > 0 && t[i] != p[matched])
			matched = pi[matched - 1];
		
		if(t[i] == p[matched]) {
			matched++;
			if(matched == m) {
				result.push_back(i - m + 2);
				matched = pi[matched - 1];
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	getline(cin,t);
	getline(cin,p);
	
	vector<int> result = kmp(t,p);
	cout << result.size() << '\n';
	for (int i=0; i<result.size(); i++)
		cout << result[i] << '\n';
}
