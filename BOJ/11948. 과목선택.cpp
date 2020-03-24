#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> sci(4);
	vector<int> soc(2);
	int a;
	int min1 = 100 , min2 = 100;
	int sum1 = 0 , sum2 = 0 ;
	for (int i=0; i<4; i++) {
		cin >> a;
		sci.push_back(a);
		sum1 += a;
		min1 = min(min1,a);
	}
	for (int i=0; i<2; i++) {
		cin >> a;
		soc.push_back(a);
		sum2 += a;
		min2 = min(min2,a);
	}
	sum1 -= min1;
	sum2 -= min2;
	cout << sum1 + sum2;
		
		
}
