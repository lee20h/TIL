#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;

int fail[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s, w;
	cin >> s >> w;
	int slen = s.length();
	int wlen = w.length();
	
	for (int i=1, j=0; i<wlen; i++) {
		while(j > 0 && w[i] != w[j])
			j = fail[j-1];
		if(w[i] == w[j])
			fail[i] = ++j;
	}
	int cnt = 0;
	for (int i=0, j=0; i<slen; i++) {
		while(j > 0 && s[i] != w[j])
			j = fail[j-1];
		if(s[i] == w[j]) {
			if(j == wlen-1) {
				cnt++;
			}
			else
				j++;
		}
	}
	if(cnt)
		cout << 1;
	else
		cout << 0;
} 
