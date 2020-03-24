#include <iostream>
using namespace std;

int main() {
	string str;
	string answer;
	cin >> str;
	for (int i=0; i<str.length(); i++)
		answer += toupper(str[i]);
	cout << answer;
}
