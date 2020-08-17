#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
int x, y;

ll ccw(pll a, pll b, pll c) {
 	ll temp = (a.first * b.second + b.first * c.second + c.first * a.second);
    temp -= (a.first*c.second + b.first*a.second + c.first * b.second);
    return temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pll> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	long long result = 0;
	for (int i=1; i<n-1; i++) {
		result += ccw(v[0], v[i], v[i+1]);
	}
	result = abs(result);
	cout << result/2 << ".";
	if(result%2 == 0)
		cout << "0";
	else
		cout << "5";
}
