#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, n;
	int max_=-1000000;
	int min_=1000000;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		max_ = max(max_,a);
		min_ = min(min_,a);
	}
	cout << min_ << ' ' << max_;
}
