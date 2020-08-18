#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

bool erato[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	long long ans = m - n + 1;
	
	for (long long i = 2; i*i <= m; i++) {
		long long start;
		if(n % (i*i) == 0)
			start = 0;
		else 
			start = i*i - (n % (i*i));
		
		for (long long j = start; j <= m-n; j += i*i) {
			if(!erato[j]) {
				ans--;
				erato[j] = true;
			}
		}
	}
	cout << ans;
}
