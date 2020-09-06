#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int fail[MAX];
int match[MAX];

/*
	match = 문자열 s1의 인덱스일 때 문자열 s2와 일치하는 길 이로, 벡터에 s1 글자에 담은다.
	제거할 문자열 찾은 경우 벡터에서 그 만큼의 길이를 제거 후 제거한 문자열의 첫 문자가 들어오기 전의 상태로 돌아간다.
	따라서 match에 벡터의 사이즈값으로 해당 값을 받아온다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	for (int i=1,j=0; i<s2.length(); i++) {
		while(j>0 && s2[i] != s2[j])
			j = fail[j-1];
		if(s2[i] == s2[j])
			fail[i] = ++j;
	}
	
	vector<char> v;
	
	for (int i=0,j=0; i<s1.length(); i++) {
		v.push_back(s1[i]);
		while(j>0 && s1[i] != s2[j])
			j = fail[j-1];
		if(s1[i] == s2[j]) {
			if(j == s2.length()-1) {
				for(int i=0; i<s2.length(); i++)
					v.pop_back();
				j = match[v.size()];
			}
			else
				j++;
		}
		match[v.size()] = j;
	}
	for (auto ans : v)
		cout << ans;
}
