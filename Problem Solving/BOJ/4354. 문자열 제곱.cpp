#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int fail[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	while(1) {
		cin >> str;
		if(str == ".")
			break;
			
		memset(fail, 0, sizeof(fail));
		
		for (int i=1, j=0; i<str.length(); i++) {
			while(j > 0 && str[i] != str[j])
				j = fail[j-1];
			if(str[i] == str[j])
				fail[i] = ++j;
		}
		
		if (fail[str.length()-1] == 0 || fail[str.length() - 1] % (str.length() - fail[str.length() - 1])) // Æç¸°µå·Ò 
            cout << 1 << '\n';
        else
			cout << str.length() / (str.length() - fail[str.length()-1]) << '\n';
	}
}
