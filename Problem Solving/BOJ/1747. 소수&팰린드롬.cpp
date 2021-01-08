#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6*2;

bool isPrime[MAX];

bool is_palindrome(string a, string b) {
	return a == b;
}

void primeInit() {
	for (int i=2; i*i<=MAX; i++) {
		if(!isPrime[i])
			for(int j=i*i; j<=MAX; j+=i)
				isPrime[j] = true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;	
	isPrime[1] = true;
	primeInit();
	
	while(1) {
		string s, r;
		
		s = to_string(n);
		r = to_string(n);
		reverse(r.begin(), r.end());
		if(is_palindrome(s, r)) {
			if(!isPrime[n])
				break;
		}
		n++;
	}
	cout << n;
}
