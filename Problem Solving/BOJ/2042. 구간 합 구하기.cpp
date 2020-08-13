#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1000000 + 1;

long long arr[MAX];
long long tree[4*MAX];

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    } else {
        return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
}
void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	
    for (int i=0; i<n; i++) 
    	cin >> arr[i];
    		
    init(1, 0, n-1);
    
    while (m--) {
        int t1;
        cin >> t1;
        
        if (t1 == 1) {
        	int t2;
        	long long t3;
            cin >> t2 >> t3;
            t2--;
            long long diff = t3 - arr[t2];
            arr[t2] = t3;
            update(1, 0, n-1, t2, diff);
        }
		else if (t1 == 2) {
            int t2, t3;
            cin >> t2 >> t3;
            cout << sum(1, 0, n-1, t2-1, t3-1) << '\n';
        }
    }
}
