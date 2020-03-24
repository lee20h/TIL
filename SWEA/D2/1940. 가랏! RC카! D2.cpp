#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	int command;
	int speed, dist;
	int a;
	for (int test=1; test<=t; test++) {
		speed = 0;
		dist = 0;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> command;
			if (command == 0) {
				dist += speed;
				continue;
			}
			else {
				cin >> a;
				if (command == 1)
					speed += a;
				else {
					speed -= a;
					if (speed<0)
						speed = 0;
				}
			}
			dist += speed;
			
		}
		cout << "#" << test << ' ' << dist << '\n';
	}
}
