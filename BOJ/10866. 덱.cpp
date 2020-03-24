#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<int> dq;
	int n;
	cin >> n;
	string str;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> str;
		
		if(str == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (str == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (str == "pop_front") {
			if(dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if(dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if(str == "size") 
			cout << dq.size() << '\n';
		else if(str == "empty") {
			if(dq.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if(str == "front") {
			if(dq.empty()) cout << "-1" << '\n';
			else cout << dq.front() << '\n';
		}
		else if(str == "back") {
			if(dq.empty()) cout << "-1" << '\n';
			else cout << dq.back() << '\n';
		}
		
	}
}
