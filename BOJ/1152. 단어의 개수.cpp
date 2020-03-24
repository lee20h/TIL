#include <iostream>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	int cnt = 1;
	str[0]==' '? cnt-- : true;
	for (int i=0; i<str.size(); i++) {
		if(str[i]==' ') {
			cnt++;
		}
	}
	str[str.size()-1]==' '? cnt--: true;
	cout << cnt;
}
