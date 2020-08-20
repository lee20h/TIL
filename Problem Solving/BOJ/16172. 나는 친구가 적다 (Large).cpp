#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000 + 1;

int fail[MAX];

/*
	일반적인 kmp 적용하여 일치하는 경우를 찾아주었다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string temp, s, w;
	cin >> temp >> w;
	int len = temp.length();
	
	for (int i=0; i<len; i++) {
		if('0' <= temp[i] && temp[i] <= '9')
			continue;
		s += temp[i];
	}
	
	
	int slen = s.length();
	int wlen = w.length();
	for (int i=1, j=0; i<wlen; i++) {
		while(j > 0 && w[i] != w[j])
			j = fail[j-1];
		if(w[i] == w[j])
			fai
			l[i] = ++j;
	}
	for (int i=0, j=0; i<slen; i++) {
		while(j > 0 && s[i] != w[j])
			j = fail[j-1];
		if(s[i] == w[j]) {
			if(j == wlen - 1) {
				cout << 1;
				return 0;
			}
			else 
				j++;
		}
	}
	
	cout << 0;
}
