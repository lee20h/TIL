#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 100000 + 1;
const int INF = 1000000001;

int arr[MAX];
int tree[4 * MAX];

int init(int node, int start, int end) {
	if(start == end)
		return tree[node] = arr[start];
	else 
		return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2 +1, end));
}

int select(int node, int start, int end, int left, int right) {
	if (left > end || right < start) 
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	
	return min(select(node*2, start, (start+end)/2, left, right), select(node*2+1, (start+end)/2+1, end, left, right));
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	init(1, 0, n-1);
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cout << select(1,0,n-1,a-1,b-1) << '\n';
	}
}
