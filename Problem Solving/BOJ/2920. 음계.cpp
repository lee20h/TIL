#include <iostream>
using namespace std;

int main() {
	int b[8];
	int a=0, d=0;
	cin >> b[0];
	for (int i=1; i<8; i++) {
		cin >> b[i];
		if(b[i-1] < b[i]) a++;
		else if (b[i-1] > b[i]) d++;
	}
	if(a==7) cout <<"ascending";
	else if (d==7) cout << "descending";
	else cout << "mixed";
}
