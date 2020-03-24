#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	int tri[10][10];
	
	for (int i=1; i<=t; i++) {
		cin >> n;
		
		for (int j=0; j<n; j++) {
			for (int k=j; k>=0; k--) {
				if (k==j || k==0) {
					tri[j][k] = 1;
				}
				else {
					tri[j][k] = tri[j-1][k-1] + tri[j-1][k];
				}
			}
		}
		
		cout << "#" << i << '\n';
		
		for (int j=0; j<n; j++) {
			
			for (int k=j; k>=0; k--) {
				cout << tri[j][k] << " ";
			}
			cout << '\n';
		}
	}
}
