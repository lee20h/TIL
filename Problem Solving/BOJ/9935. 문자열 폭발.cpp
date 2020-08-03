#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<char> v;
	bool flag;
	string str;
	string bomb;
	cin >> str >> bomb;
	int blen = bomb.length();
	int len = str.length();
	int cnt = 0;
	for (int i=0; i<len; i++) {
		flag = true;
		int idx = i - cnt;
		v.push_back(str[i]);
		
		for (int j=blen-1; j >= 0; j--) {
			if(v[idx--] == bomb[j]) continue;
			else {
				flag = false;
				break;
			}
		}
		
		if(flag) {
			for (int j=0; j<blen; j++) {
				v.pop_back();
				cnt++;
			}
		}
	}
	
	if(v.empty()) cout << "FRULA";
	else {
		for (int i=0; i<v.size(); i++)
			cout << v[i];
	}
}
