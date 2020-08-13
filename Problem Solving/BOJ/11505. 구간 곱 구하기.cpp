#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000 + 1;
const int DIV = 1000000007;

int arr[MAX];
int tree[4*MAX];

long long init(int node, int start, int end) {
	if(start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end) % DIV;
}

long long update(int node, int start, int end, int idx, int val) {
	if(idx < start || end < idx)
		return tree[node];
	if(start == end)
		return tree[node] = val;
	
	return tree[node] = update(node*2, start, (start+end)/2, idx, val) * update(node*2+1, (start+end)/2+1, end, idx, val) % DIV;
}

long long mul(int node, int start, int end, int left, int right) {
	if(right < start || end < left)
		return 1;
	if(left <= start && end <= right)
		return tree[node] ;
		
	return mul(node*2, start, (start+end)/2, left, right) * mul(node*2+1, (start+end)/2+1, end, left, right) % DIV;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	init(1,0,n-1);
	m += k;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			b--;
			arr[b] = c;
			update(1,0,n-1,b,c);
		}
		else if (a == 2) {
			cout << mul(1,0,n-1,b-1,c-1) << '\n';
		}
	}
}
