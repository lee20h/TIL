#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int arr[7][7];
	int n;
	int a[7][7];
	int b[7][7];
	int c[7][7];
	for (int test=1; test<=t; test++) {
		cin >> n;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				a[i][j] = arr[n-1-j][i];
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				b[i][j] = a[n-1-j][i];
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				c[i][j] = b[n-1-j][i];
			}
		}
		cout << "#" << test << '\n';
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << a[i][j];
			}
			cout << ' ';
			for (int j=0; j<n; j++) {
				cout << b[i][j];
			}
			cout << ' ';
			for (int j=0; j<n; j++) {
				cout << c[i][j];
			}
			cout << '\n';
		}
		
	}
	return 0;
}
