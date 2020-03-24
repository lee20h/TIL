#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> array(10);
	int sum, _min, _max;
	double aver;
	for (int test=1; test<=t; test++) {
		sum=0;
		_min = 10000;
		_max = 0;
		for (int i=0; i<10; i++) {
			cin >> array[i];
			sum += array[i];
			_max = max(_max, array[i]);
			_min = min(_min, array[i]);
		}
		aver = double(sum - _max - _min) / 8;
		cout << "#" << test << ' ' << round(aver) << '\n';
	}
	return 0;
}
