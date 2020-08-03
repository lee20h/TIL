#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int test;
	string cmd;
	cin >> test;
	int n;
	for (int t=0; t<test; t++) {
		deque<int> dq;
		cin >> cmd;
		cin >> n;
		string temp, str;
		cin >> str;
		temp.clear();
		for (int i=0; i<str.length(); i++) {
			if(str[i] == '[')
				continue;
			else if('0' <= str[i] && str[i] <= '9')
				temp += str[i];
			else if (str[i] == ',' || str[i] == ']') {
				if(!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}		
		}
		bool chk = false;
		bool rev = false;
		
		for (int i=0; i<cmd.length(); i++) {
			if(cmd[i] == 'R') {
				rev = !rev;
			}
			else {
				if(dq.empty()) {
					cout << "error" << '\n';
					chk = true;
					break;
				}
				else {
					if(rev) dq.pop_back();
					else dq.pop_front();
				}
			}
		}
		if(!chk) {
			if(!rev) {
				cout << "[";
				while(!dq.empty()) { 
					cout << dq.front();
					dq.pop_front();
					if(!dq.empty())
						cout << ",";
				}
			}
			else {
				cout << "[";
				while(!dq.empty()) { 
					cout << dq.back();
					dq.pop_back();
					if(!dq.empty())
						cout << ",";
				}
			}
			cout << "]" << '\n';
		}
	}
}
