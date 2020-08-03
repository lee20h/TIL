#include <iostream>
using namespace std;

int main() {
	int price, count, money;
	cin >> price >> count >> money;
	price = price * count;
	if (price > money) cout << price - money;
	else cout << "0";
}
