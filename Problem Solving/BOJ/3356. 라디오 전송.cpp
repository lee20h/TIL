#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;

int fail[MAX];

/*
	메시질르 확실하게 받게 하기 위해서 계속 반복 전송한다고 한다.
	이때 받는 메시지의 길이는 보낸 메시지의 길이보다 크거나 같으므로
	해당 부분수열을 구하되 가장 짧은 부분수열을 구하는 것이다.
	따라서 실패함수를 구한 다음, 해당 길이에서 빼준다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	for (int i=1,j=0; i<n; i++) {
		while(j>0 && s[i] != s[j])
			j = fail[j-1];
		if(s[i] == s[j])
			fail[i] = ++j;
	}
	
	cout << n - fail[n-1];
}
