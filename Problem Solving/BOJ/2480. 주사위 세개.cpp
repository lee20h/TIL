#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> dice;
	int count = 0;
	int a;
	int idx = -1;
	for (int i=0; i<3; i++) {
		cin >> a;
		dice.push_back(a);
	}
	sort(dice.begin(),dice.end());
	
	for (int i=1; i<3; i++) {
		if (dice[i-1] == dice[i]) {
			count++;
			idx=i;
		}
	}
	if (count==2) {
		cout << 10000 + dice[idx] * 1000;
	}
	else if(count==1) {
		cout << 1000 + dice[idx] * 100;
	}
	else {
		cout << dice[2]*100;
	}
	
}
