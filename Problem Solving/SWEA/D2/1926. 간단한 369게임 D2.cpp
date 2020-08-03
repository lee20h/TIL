#include <iostream>
using namespace std;

int main() {
	int n;
	int h,t,o;
	int count=0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		h=i/100;
		t=(i/10)%10;
		o=i%10;
		if(h%3==0 && h!=0) count++;
		if(t%3==0 && t!=0) count++;
		if(o%3==0 && o!=0) count++;
		
		if(count != 0) {
			for (int i=0; i<count; i++)
				cout << "-";
			cout << ' ';
			count = 0;
		}
		
		else
			cout << i << ' ';
	}
}
