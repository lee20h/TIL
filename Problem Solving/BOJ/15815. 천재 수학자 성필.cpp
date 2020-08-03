#include <iostream>
#include <stack>
using namespace std;

int main() {
	string c;
	stack<int> s;
	int first, second;
	int temp;
	cin >> c;

	for (int i = 0; i < c.length(); i++) {
		if (c[i] >= '0' && c[i] <= '9') {
			s.push(c[i]-'0');
		}
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
			second = s.top();
			s.pop();
			first = s.top();
			s.pop();
			if (c[i] == '+') {
				temp = first + second;
			}
			else if (c[i] == '-') {
				temp = first - second;
			}
			else if (c[i] == '*') {
				temp = first * second;
			}
			else {
				if (second == 0) {
					return 0;
				}
				temp = first / second;
			}
			s.push(temp);
		}
	}
	
	cout << s.top();

	return 0;
}
