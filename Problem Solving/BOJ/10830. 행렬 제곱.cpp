#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long n, b;

vector<vector<ll>> mul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
	vector<vector<ll>> ret(n, vector<ll>(n));
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<n; j++) {
			for (ll k=0; k<n; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= 1000;
		}
	}
	return ret;
}


vector<vector<ll>> power(vector<vector<ll>> mat, ll num) {
	vector<vector<ll>> ret(n, vector<ll>(n));
	for (int i=0; i<n; i++) {
		ret[i][i] = 1;
	} 
	
	while(num > 0) {
		if (num % 2) {
			ret = mul(ret, mat);
		}
		num /= 2;
		mat = mul(mat, mat);
	}
	return ret;
}

void printmat(const vector<vector<ll>> &matrix) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> b;
	vector<vector<ll>> matrix(n, vector<ll>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	printmat(power(matrix,b));
	
}
