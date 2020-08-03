#include <iostream>
#include <queue>
using namespace std;

int main() {
	for (int t=1; t<=10; t++) {
		int testcase;
		cin >> testcase;
		queue<int> q;
		for (int i=0; i<8; i++) {
			int n;
			cin >> n;
			q.push(n);
		}
		int num = 1;
		while(1) {
			if(num > 5) num = 1;
			int temp = q.front();
			q.pop();
			temp = temp - num;
			if(temp <= 0) {
				q.push(0);
				break;
			}
			q.push(temp);
			num++;
		}
		
		cout << "#" << t << ' ';
		for (int i=0; i<8; i++) {
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
	}
}
