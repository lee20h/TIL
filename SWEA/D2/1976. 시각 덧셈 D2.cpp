#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int min;
	int hour;
	int sum=0;
	for (int test=1; test<=t; test++) {
		sum=0;
		
		for (int i=0; i<2;i++) {
			cin >> hour >> min;
			sum += hour*60;
			sum += min;
		}
		if(sum/60==24)
			hour=12;
		else hour = sum/60%12;
		min = sum%60;
		
		cout << "#" << test << ' ' << hour << ' ' << min << '\n';
		
	}
	return 0;
}
