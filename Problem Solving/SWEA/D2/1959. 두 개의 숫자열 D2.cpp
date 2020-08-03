#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int t;
	int n, m;
	int a[20], b[20];
	int _max;
	int length;
	int sum;
	cin >> t;
	for (int test=1; test<=t; test++) {
		cin >> n >> m;
		sum = 0;
		length = max(n,m) - min(n,m) + 1;
		for (int i=0; i<n; i++)
			cin >> a[i];
		for (int i=0; i<m; i++)
			cin >> b[i];
		_max = -99999999999;
		if (n>m) {
			for (int i=0; i<length; i++) {
				sum = 0;
				for (int j=0; j<m; j++)
					sum += a[i+j] * b[j];
				_max = max(_max, sum);
			}
		}
		else {
			for (int i=0; i<length; i++) {
				sum = 0;
				for (int j=0; j<n; j++)
					sum += a[j] * b[i+j];
				_max = max(_max, sum);
			}
		}
		cout << "#" << test << ' ' << _max << '\n';
	}
	return 0;
}
