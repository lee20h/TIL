#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	cin >> n;
	int sum;
	int count = 1;
	if(n==1) {
		cout << "1";
		return 0;
	}
	while(1) {
		sum = 0;
		for(int i=2; i<=count; i++) {
			sum += 6*i;
		}
		if(n-sum<8) break;
		count++;
	}
	cout << count+1;
}
