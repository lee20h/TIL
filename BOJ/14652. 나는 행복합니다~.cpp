#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int a = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++,a++) {
			if (a==q) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
}

