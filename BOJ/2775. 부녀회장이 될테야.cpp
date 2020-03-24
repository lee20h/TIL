#include <iostream>
#include <vector>
using namespace std;


vector<int> v[15];

int main() {
	int testcase;
	int k, n;
	int temp = 0;
	cin >> testcase;
	for (int i=0; i<=14; i++)
		v[0].push_back(i);
	for (int i=1; i<=14; i++) {
		v[i].push_back(0);
		for (int j=1; j<=15; j++) {
			temp = 0;
			for (int l=1; l<=j; l++) {
				temp += v[i-1][l];
			}
			v[i].push_back(temp);
		}
	}
	for (int t=0; t<testcase; t++) {
		cin >> k >> n;
		cout << v[k][n] << '\n';
	}
}
