#include <bits/stdc++.h>
using namespace std;

int alpha[26];
int word[15];
int answer;
int n;
const int correct = 0x3ffffff;

void sol(int begin, int curWord) {
	if (curWord == correct) {
		answer += 1;
	}
	for (int i=begin; i<n; i++) {
		sol(i+1, curWord | word[i]);
	}
}

int main() {
	for (int i=0; i<26; i++) {
		alpha[i] = 0x01 << i;
	}
	
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		cin >> n;
		string str;
		
		for (int i=0; i<n; i++) {
			cin >> str;
			int m = 0;
			for (int j=0; j<str.length(); j++) {
				m |= alpha[str[j] - 'a'];
			}
			word[i] = m;
		}
		answer = 0;
		sol(0,0);
		cout << "#" << t << ' ' << answer << '\n';
	}
}
