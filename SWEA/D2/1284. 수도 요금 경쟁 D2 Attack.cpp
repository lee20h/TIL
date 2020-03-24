#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int p,q,r,s,w;
	int charge;
	int sudo1;
	int sudo2;
	for (int test=1; test<=t; test++) {
		cin >> p >> q >> r >> s >> w;
		sudo1 = p*w;
		if(r<w) {
			sudo2 = q + s*(w-r);
		}
		else sudo2 = q;
		charge = sudo1>sudo2 ? sudo2:sudo1;
		cout << "#" << test << ' ' << charge << '\n';
	}
	return 0;
}
