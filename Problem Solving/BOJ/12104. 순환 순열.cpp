#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;
int fail[MAX];

/*
	순환 문자열을 환형 문자열과 같이 보아서 두배로 늘려준 뒤 KMP알고리즘을 쓰되 길이를 문자열의 길이만큼만 세어주었다.
	이후 자기 자신은 빼줘야하므로 조건에서 1을 빼며, xor연산에서 0이 나오는 건 같은 부분이므로 그대로 찾는다. 
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, str2;
	int ans = 0;
	cin >> str;
	cin >> str2;
	
	str += str;
	
	for (int i=1, j=0; i<str2.length(); i++) {
		while(j>0 && str2[i] != str2[j])
			j = fail[j-1];
		if(str2[i] == str2[j])
			fail[i] = ++j;
	}
	
	for (int i=0, j=0; i<str.length()-1; i++) {
		while(j>0 && str[i] != str2[j])
			j = fail[j-1];
		if(str[i] == str2[j]) {
			if(j == str2.length()-1) {
				ans++;
				j = fail[j];
			}
			else
				j++;
		}
	}
	
	cout << ans;
}
