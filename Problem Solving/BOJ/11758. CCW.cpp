#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	int pos = x1 * y2 + x2 * y3 + x3 * y1;
	pos = pos - y1 * x2 - y2 * x3 - y3 * x1;
	if(pos > 0)
		cout << 1;
	else if(pos < 0)
		cout << -1;
	else
		cout << 0;
}
