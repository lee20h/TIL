#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if(m-45<0){
		if(h==0) {
			m = m+60-45;
			h = 23;
		}
		else {
			m = m+60-45;
			h = h-1;
		}
		
	}
	else
		m = m-45;
	cout << h << ' ' << m;
}
