#include <iostream>
using namespace std;

string str;
string temp;
int sum;
bool mi = false;
void sol() {
	for (int i=0; i<=str.length(); i++) {
		
		if(str[i]=='+' || str[i]=='-' || str[i]=='\0') {
			
			if(mi) sum -= stoi(temp);
			else sum += stoi(temp);
			
			if(str[i]=='-') mi = true;
			temp.clear();
			
			continue;
		}
		
		temp += str[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	sol();
	cout << sum;
}
