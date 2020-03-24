#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n;
	cin >> n;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << '\n';
	}
}
