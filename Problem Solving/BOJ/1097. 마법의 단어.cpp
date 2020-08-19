#include <bits/stdc++.h>
using namespace std;

int fail[1000 + 1];
/*
	T를 쉬프트한 문자열 (최대 T.length()개)가 T와 같아지는 경우가 K번 존재
	문자열들이 주어졌을 때 순열의 조합으로 만들 수 있는 단어 중 몇개냐
	순열은 next_permutation 사용하고 kmp를 통해 구하되, 주어진 문자열의 끝까지 가게되면
	자기 자신과 같으므로 length()에서 -1만큼 해준다. 
*/
int kmp(string a, string b) {
	memset(fail, 0, sizeof(fail));
	int cnt = 0;
	for (int i=1, j=0; i<a.length(); i++) {
		while(j > 0 && a[i] != b[j])
			j = fail[j-1];
		if(a[i] == b[j])
			fail[i] = ++j;
	}
	for (int i=0, j=0; i<a.length()-1; i++) {
		while(j > 0 && a[i] != b[j])
			j = fail[j-1];
		if(a[i] == b[j]) {
			if(j == b.length()-1) {
				cnt++;
				j = fail[j];
			}
			else
				j++;
		}
			
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	vector<string> str;
	vector<int> v;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		v.push_back(i);
		str.push_back(s);
	}
	
	cin >> k;
	int cnt = 0;
	
	do {
		string comb, word;
		for (int i=0; i<n; i++)
			word += str[v[i]];
		
		comb = word + word;
		
		if(kmp(comb, word) == k)
			cnt++;
		
	}while(next_permutation(v.begin(),v.end()));
	cout << cnt;
} 
