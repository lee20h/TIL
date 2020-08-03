#include <iostream>
using namespace std;

int main() {
	int n[9];
	int max_=0;
	int index;
	for (int i=0; i<9; i++) {
		cin >> n[i];
		max_ < n[i]? max_ = n[i], index = i+1 : true;
	}
	cout << max_ << '\n' << index;
}
