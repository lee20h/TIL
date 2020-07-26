#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int v[16];

bool check(int q) {
	int temp = 1;
	while(temp < q) {
		if(v[q] == v[temp] || abs(v[q] - v[temp]) == q - temp)
			return false;
		temp++;
	}
	return true;
}

void nqueens(int q) {
	if(check(q)) {
		if(q == n) ans++;
		else {
			for (int i=1; i<=n; i++) {
				v[q+1] = i;
				nqueens(q+1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	nqueens(0);
	cout << ans;
	
}
