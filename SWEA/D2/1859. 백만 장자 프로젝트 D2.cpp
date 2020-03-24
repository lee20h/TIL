#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	int day;
	int temp;
	int max;
	long long result=0;
	vector<long long> prices(1000001);
	cin >> t;
	for (int i=1; i<=t; i++) {
		cin >> day;
		result = 0;
		for (int j=0; j<day; j++) {
			cin >> temp;
			prices[j] = temp;
		}
		max = prices[day-1];
		
		for (int i=day-1; i>=0; i--) {
			if(max<=prices[i]) {
				max=prices[i];
			}
			else {
				result += max - prices[i];
			}
		}
		
		cout << "#" << i << ' ' << result << '\n';
	}
	return 0;
}
