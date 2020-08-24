#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;
int fail[MAX];

/*
	접두사와 접미사가 둘 다 되는 것 중 가장 긴건 문자열의 길이 N이다.
	두번째로 긴 것은 fail(n), 세번쨰로 긴 것은 fail(fail(n))이다.
	따라서 이렇게 따라 내려가다보면 접두사와 접미사가 모두 되는 문자열이 나온다.
	그들 중 접두사와 접미사를 제외하고 최소 한번 더 나타나나 체크해서 그 문자열을 출력하면 되는데,
	여기서 앞뒤로 문자 하나를 빼서 접두사 와 접미사를 제외하게 해서 찾았다. 
*/
int main() {
	string str;
	cin >> str;
	int ans = 0;
	for(int i=1,j=0; i<str.length(); i++) {
		while(j>0 && str[i] != str[j])
			j = fail[j-1];
		if(str[i] == str[j]) {
			fail[i] = ++j;
		}
	}
	
	int pivot = fail[str.length() - 1];
	bool flag = false;
	while(pivot) {
		for (int i=1; i<str.length()-1; i++) {
			if(fail[i] == pivot) {
				for (int j=0; j<pivot; j++) {
					cout << str[j];
				}
				flag = true;
				break;
			}
		}
		
		if(flag) break;
		pivot = fail[pivot-1];
	}
	if(!flag)
		cout << -1;
}
