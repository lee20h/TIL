#include <iostream>
using namespace std;

int num[26];

int main() { // -64
	string str;
	int max = 0;
	int cnt = 0;
	int index;
	cin >> str;
	for (int i=0; i<str.size(); i++) {
		str[i] = toupper(str[i]);
		num[str[i]-65] += 1;
	}
	for (int i=0; i<26; i++) {
		if(max<num[i]) {
			max = num[i];
			index = i;
		}
	}
	for (int i=0; i<26; i++) {
		if(max==num[i]) cnt++;
	}
	if(cnt==1) {
		cout << (char)(index+65);
	}
	else cout << "?";
}
