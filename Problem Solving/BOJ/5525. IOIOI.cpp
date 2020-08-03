#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int n, m;
	cin >> n >> m;
	cin >> str;
	int cnt = 0;
	int temp = 0;
	for (int i=1; i<m-1; i++) {
		if(str[i-1] == 'I' && str[i] == 'O' && str[i+1] == 'I') {
			temp++;
			if(n == temp) {
				cnt++;
				temp--;
			}
			i++;
		}
		else temp = 0;
	}
	cout << cnt;
}
