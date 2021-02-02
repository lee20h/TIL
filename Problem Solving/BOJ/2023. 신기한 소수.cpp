#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int obj;

bool prime(int n) {
	if(n == 0 || n == 1)
		return false;
		
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

void dfs(int n, int cnt) {
	if(cnt == obj) {
		cout << n << '\n';
		return;
	}
	
	for (int i=1; i<10; i++) {
		if(prime(n*10+i))
			dfs(n*10+i, cnt+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> obj;
	
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}
