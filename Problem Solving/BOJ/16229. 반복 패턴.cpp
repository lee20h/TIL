#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;

int fail[MAX];

/*
	반복 패턴을 만들기 위해서 실패함수를 사용하는데 실패함수의 특징이 접두사와 접미사가 일치하는 것을 찾는것이다.
	fail[n]은 접미사와 접두사가 가장 큰 값이 들어있다. 이 부분을 fail[fail[n]]을 계속 반복해서
	해당 반복 패턴을 찾을 수 있다. 
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int ans = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	
	for (int i=1, j=0; i<n; i++) {
		while(j>0 && str[i] != str[j])
			j = fail[j-1];
		if(str[i] == str[j])
			fail[i] = ++j;
	}
	
	if(n <= k)
		cout << n;
	else { // pattern 패턴 길이, cnt 패턴 횟수 
		for (int i= fail[n-1]; i>0; i = fail[i-1]) {
			int pattern = n-i;
			int cnt = (n+k)/pattern;
			if(cnt >= 2 && cnt * pattern >= n)
				ans = max(ans, pattern);
		}
		cout << ans;
	}
	
} 
