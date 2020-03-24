#include <iostream>
using namespace std;

int main() {
	string str;
	int n;
	cin >> n;
	int inc;
	int score;
	for (int i=0; i<n; i++) {
		score = 0;
		inc = 0;
		cin >> str;
		for (int j=0; j<str.size();j++) {
			if(str[j]=='O') {
				inc++;
				score += inc;
			}
			else {
				inc = 0;
			}
		}
		cout << score << '\n';
	}
}
