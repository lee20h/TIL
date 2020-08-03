#include <iostream>
#include <string> 
using namespace std;

int main() {
	string n;
	cin >> n;
	int len = n.length();
	int sum = 0;
	string temp;
	int num;
	bool flag = false;
	for (int i=len*9; i>1; i--) {
		sum = 0;
		num = stoi(n) - i;
		temp = to_string(num);
		for (int j=0; j<temp.length(); j++) {
			sum += temp[j] - '0';
		}
		if (sum==i) {
			flag = true;
			break;
		}
	}
	if (flag) cout << num;
	else cout << 0;
}
