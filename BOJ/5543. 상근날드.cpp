#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int burger, bever;
	int min_burger, min_bever;
	min_burger = min_bever = 2001;
	for (int i=0; i<3; i++) {
		cin >> burger;
		min_burger = min(min_burger,burger);
	}
	for (int i=0; i<2; i++) {
		cin >> bever;
		min_bever = min(min_bever,bever);
	}
	cout << min_burger + min_bever - 50;
}
