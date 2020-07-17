#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;
	
	for (int i=0; i<n; i++) {
		cin >> m;
		if(max_q.size() == min_q.size())
			min_q.push(m);
		else
			max_q.push(m);
			
		
		if(!max_q.empty() && !min_q.empty())
			while(max_q.top() > min_q.top()) {
				int max = max_q.top();
				int min = min_q.top();
				max_q.pop();
				min_q.pop();
				max_q.push(min);
				min_q.push(max);
			}
		if(i%2 ==0)
			cout << min_q.top() << '\n';
		else
			cout << max_q.top() << '\n';
	}
}
