#include <iostream>
using namespace std;

int main() {
	int row, col;
	int n;
	cin >> n;
	row = n/2;
	col = n - row;
	cout << (row+1) * (col+1);
}
