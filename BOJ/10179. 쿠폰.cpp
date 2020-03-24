#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	vector<double> v;
	cin >> testcase;
	cout << fixed;
	cout.precision(2);
	for (int i=0; i<testcase; i++) {
		double n;
		cin >> n;
		v.push_back(n);
	}
	for (int i=0; i<v.size(); i++) {
		cout << "$" << v[i] * 0.8 << '\n';
	}
}
