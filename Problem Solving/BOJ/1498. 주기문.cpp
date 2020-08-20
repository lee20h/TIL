#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

int fail[MAX];

/*
	문자열의 n 제곱이란 부분문자열을 n번 이어붙였을 대 해당 문자열이 나와야하기 때문에
	접두사이면서 접미사인 부분문자열의 길이를 실패함수를 통해서 저장한다.
	따라서 문자열의 인덱스 - 1일 때 부분문자열의 길이는 문자열을 n번 제곱했을 때의 부분문자열의 길이이다.
	즉, length / length - fail[leength-1] 이 제곱을 뜻하며 펠린드롬을 제외해주고 찾아주면 된다. 
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n = 0;
	for (int i=1, j=0; i<str.length(); i++) {
		while(j > 0 && str[i] != str[j])
			j = fail[j-1];
		if(str[i] == str[j]) {
			fail[i] = ++j;
		}
	}
	
	for (int i=2; i<=str.length(); i++) {
		if (fail[i-1] == 0 || fail[i - 1] % (i - fail[i - 1])) // 펠린드롬 
			continue;
		int ans = i / (i - fail[i-1]); // 제곱수 
		if(ans > 1) { // 제곱을 갖는 경우 
			cout << i << ' ' << ans << '\n';
		}
	}
}
