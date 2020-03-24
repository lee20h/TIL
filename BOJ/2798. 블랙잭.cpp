#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	int n, m;
	vector<int> v;
	cin >> n >> m;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	int sum;
	temp = 0;
	for (int i=0; i<n-2; i++) {
		for (int j=i+1; j<n-1; j++) {
			for (int k=j+1; k<n; k++) {
				sum = v[i] + v[j] + v[k];
				if(sum<=m) {
					if(sum>temp) temp = sum;
					if(sum==m) {
						cout << m;
						return 0;
					}
				}
			}
		}
	}
	cout << temp;
}
