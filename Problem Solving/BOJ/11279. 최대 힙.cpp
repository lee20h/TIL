#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> q;
	int n;
	cin >> n;
	int num;
	for (int i=0; i<n; i++) {
		cin >> num;
		if(num==0) {
			if(q.empty())
				cout << "0" << '\n';
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else q.push(num);
	}
}
