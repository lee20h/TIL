#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;
const int INF = 1e9;
int fail[MAX], dp[MAX];
/*
	Prefix와 Suffix가 같은 0이 아닌 가장 작은 길이를 구한다음에 X의 길이에서 뺀뒤 이 값을 답에 누적한다
*/

int sol(int pos) {
	if(pos < 0 || fail[pos] == 0)
		return INF;
		
	int& ret = dp[pos];
	if(ret != -1)
		return ret;
		
	return ret = min(fail[pos], sol(fail[pos-1]));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str;
	cin >> n >> str;
	
	for(int i=1,j=0; i<n; i++) {
		while(j>0 && str[i] != str[j])
			j = fail[j-1];
		if(str[i] == str[j])
			fail[i] = ++j;
	}
	memset(dp, -1, sizeof(dp));
	
	long long sum = 0;
	for (int i=0; i<n; i++) {
		int ret = sol(i);
		if(ret == INF)
			continue;
		sum += (long long)(i-ret+1);
	}
	cout << sum;
}
