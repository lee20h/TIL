#include <bits/stdc++.h>
using namespace std;

vector<char> ch;
vector<string> v;
int l, c;

bool vowel(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

void dfs(int cur, string str) {
	if(str.length() == l) {
		int cnt = 0;
		for (int i=0; i<l; i++) {
			if(vowel(str[i])) {
				cnt++;
			}
		}
		if(cnt >= 1 && l - cnt >= 2)
			v.push_back(str);
		return;
	}
	
	for(int i=cur+1; i<c; i++) {
		str += ch[i];
		dfs(i, str);
		str.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i=0; i<c; i++) {
		char temp;
		cin >> temp;
		ch.push_back(temp);
	}
	
	sort(ch.begin(), ch.end());
	
	for (int i=0; i<c; i++) {
		string temp;
		temp += ch[i];
		dfs(i, temp);
	}
	
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
}
