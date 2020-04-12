#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	vector<int> v2;
	int n;
	int temp;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
		v2.push_back(temp);
	}
	sort(v2.begin(),v2.end());
	v2.erase(unique(v2.begin(),v2.end()),v2.end());
	vector<int>::iterator low;
	for (int i=0; i<n; i++) {
		int num = v[i];
		low = lower_bound(v2.begin(),v2.end(), num);
		cout << (low - v2.begin())<< ' ';
	}
}
