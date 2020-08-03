#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main () {
	int t;
	cin >> t;
	vector<int> arr;
	int n, temp;
	for (int test=1; test<=t; test++) {
		cin >> n;
		arr.clear();
		for (int i=0; i<n; i++) {
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(),arr.end());
		cout << "#" << test << ' ';
		for (int i=0; i<n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
