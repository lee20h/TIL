#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	int n;
	cin >> n;
	for (int i=3; i<=n+1; i++) {
		v.push_back(v[i-1] + v[i-2]);
	}
	long long ans = 2*v[n-1] + 2*v[n];
	cout << ans;
}
