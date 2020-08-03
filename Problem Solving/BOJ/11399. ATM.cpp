#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<=i; j++) {
			sum += v[j];
		}
	}
	cout << sum;
}
