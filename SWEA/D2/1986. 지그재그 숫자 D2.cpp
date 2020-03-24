#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	int sum;
	for (int test = 1; test<=t; test++) {
		cin >> n;
		sum=0;
		for (int i=1; i<=n; i++) {
			if(i%2==0) {
				sum-=i;
			}
			else {
				sum+=i;
			}
		}
		cout << "#" << test << ' ' << sum << '\n';
	}
}
