#include <bits/stdc++.h>
using namespace std;

string short_str[501];
int fail[501][10001];
int dp[100001];
int mem[501];

/*
	fail 함수를 매번 돌리면서 하나하나 비교하게되면 메모리 초과가 뜨게 된다.
	따라서 짧은 문자열의 실패함수를 모두 구한 다음 긴 문자열의 인덱스 전부에서
	짧은 문자열에 대해 kmp를 진행한다. 이때 kmp의 인덱스를 i를 긴 문자열 길이 j를 짧은 문자열로
	잡고 돌리되, 동적계획법을 생각해서 현재의 인덱스는 이전의 인덱스의 값을 모두 가지고 시작한다.
	그 후 일치한 경우 해당 값을 더하고 더 큰 값을 취하는 식으로 한다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	int t;
	cin >> str >> t;
	int Len = str.length();
	for (int i=0; i<t; i++) {
		cin >> short_str[i];
		
		int len = short_str[i].length();
		
		for (int idx=1,j=0; idx<len; idx++) {
			while(j>0 && short_str[i][idx] != short_str[i][j])
				j = fail[i][j-1];
			if(short_str[i][idx] == short_str[i][j])
				fail[i][idx] = ++j;
		}
	}
	
	for (int i=0; i<Len; i++)  {
		if(i != 0)
			dp[i] = dp[i-1];
			
		for (int j=0; j<t; j++) {
			int len = short_str[j].length();
			
			while(mem[j]>0 && str[i] != short_str[j][mem[j]])
				mem[j] = fail[j][mem[j]-1];
			if(str[i] == short_str[j][mem[j]]) {
				if(mem[j] == len-1) { // 긴 문자열에 다 들어간 경우 
					int value = i - len >= 0 ? dp[i-len] : 0;
					value += len;
					dp[i] = max(dp[i], value);
					mem[j] = fail[j][mem[j]];
				}
				else
					mem[j]++;
			}
		}
	}
	cout << dp[Len-1];
	
}
