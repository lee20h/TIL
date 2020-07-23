#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first && b.second < b.second) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, answer = 0;
	cin >> n;

	vector<pair<int,int>> v;
	int d, w;
	for (int i=0; i<n; i++) {
		cin >> d >> w;
		v.push_back({d,w});
	}

	sort(v.begin(), v.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i=0; i<n; i++)
	{
		if (pq.size() < v[i].first)
			pq.push(v[i].second);
		else {
			if (pq.top() < v[i].second)
			{
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}

	while (!pq.empty()){
		answer += pq.top();
		pq.pop();
	}

	cout << answer << '\n';

	return 0;
}
