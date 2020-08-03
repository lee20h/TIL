#include <bits/stdc++.h>
using namespace std;

int main() {
	int money;
	cin >> money;
	money = 1000 - money; 
	int answer = 0;
	while(money) {
		if(money>=500) {
			money -= 500;
			answer++;
		}
		else if (money >=100) {
			money -= 100;
			answer++;
		}
		else if (money >= 50) {
			money -= 50;
			answer++;
		}
		else if (money >= 10) {
			money -= 10;
			answer++;
		}
		else if (money >= 5) {
			money -= 5;
			answer++;
		}
		else {
			money -= 1;
			answer++;
		}
	}
	cout << answer;
}
