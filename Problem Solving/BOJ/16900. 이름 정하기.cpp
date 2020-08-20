#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;
long long fail[MAX];
/*
	KMP 실패함수를 이용해서 부분 문자열을 구한다. 
	접두사와 접미사가 같으므로 전체 길이에서 반복되는 길이만큼을 빼고 n-1을 곱해준다.
	그 다음 전체 길이와 더하면 된다. n-1인 이유는 자기 자신을 제외하기 때문이다. 
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c;
	long long n;
	cin >> c >> n;
	long long len = c.length();
	for (int i=1, j=0; i<len; i++) {
		while(j>0 && c[i] != c[j])
			j = fail[j-1];
		if(c[i] == c[j]) 
			fail[i] =  ++j;
	}
		
	cout << len + (len-fail[len-1]) * (n-1);
}

