#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n, k;
	int puzzle[15][15] = {0,};
	int count = 0;
	int length=0;
	for (int test=1; test<=t; test++) {
		
		cin >> n >> k;
		count = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> puzzle[i][j];
			}
		}
		
		for (int i=0; i<n; i++) { //가로 
			for (int j=0; j<n; j++) {
				if(puzzle[i][j] == 1) {
					length++;
				}
				else {
					if (length==k)
						count++;
					length = 0;
				}
			}
			if (length == k)
				count++;
			length = 0;
		}
		for (int i=0; i<n; i++) { //가로 
			for (int j=0; j<n; j++) {
				if(puzzle[j][i] == 1) {
					length++;
				}
				else {
					if (length==k)
						count++;
					length = 0;
				}
			}
			if (length == k)
				count++;
			length = 0;
		}
		
		
		cout << "#" << test << ' ' << count << '\n';
	}
	return 0;
}
