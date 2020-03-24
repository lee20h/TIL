#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	queue<int> q;
	for (int i=1; i<=n; i++)
		q.push(i);
	cin >> k;
	
	cout << "<";
	while(!q.empty()) {
		for (int i=0; i<k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front();
		q.pop();
		
		if(!q.empty()) cout << ", ";
	}
	cout << ">";
	
	return 0;
}
