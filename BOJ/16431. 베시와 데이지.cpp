#include <iostream>
using namespace std;

int main() {
	int bx, by, dx, dy, jx, jy;
	cin >> bx >> by;
	cin >> dx >> dy;
	cin >> jx >> jy;
	int d = abs(jx-dx) + abs(jy-dy);
	int pos1 = abs(jx-bx);
	int pos2 = abs(jy-by);
	int b;
	if(pos1<pos2) b = pos2;
	else b = pos1;
	
	if(d==b) cout << "tie";
	else if(d>b) cout << "bessie";
	else cout << "daisy";
} 
