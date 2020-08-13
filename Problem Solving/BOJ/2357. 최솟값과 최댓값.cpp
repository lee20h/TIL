#include <iostream>
#include <vector>
using namespace std;

const int INF = 2e9 + 1;
const int MAX = 100000 + 1;

int arr[MAX];
int max_tree[4*MAX];
int min_tree[4*MAX];

int max_init(int node, int start, int end) {
	if(start == end)
		return max_tree[node] = arr[start];
	else 
		return max_tree[node] = max(max_init(node*2, start,(start+end)/2), max_init(node*2+1, (start+end)/2+1, end));
}

int min_init(int node, int start, int end) {
	if(start == end)
		return min_tree[node] = arr[start];
	else 
		return min_tree[node] = min(min_init(node*2, start,(start+end)/2), min_init(node*2+1, (start+end)/2+1, end));
}

int max_select(int node, int start, int end, int left, int right) {
	if(left > end || right < start)
		return 0;
	if(left <= start && end <= right)
		return max_tree[node];
	
	return max(max_select(node*2, start, (start+end)/2, left, right), max_select(node*2+1, (start+end)/2+1, end, left, right));
}

int min_select(int node, int start, int end, int left, int right) {
	if(left > end || right < start)
		return INF;
	if(left <= start && end <= right)
		return min_tree[node];
	
	return min(min_select(node*2, start, (start+end)/2, left, right), min_select(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	max_init(1,0,n-1);
	min_init(1,0,n-1);
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cout << min_select(1,0,n-1,a-1,b-1) << ' ' << max_select(1,0,n-1,a-1,b-1) << '\n';
	}
}
