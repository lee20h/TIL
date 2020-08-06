#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 1;

int in[MAX];
int post[MAX];
int inidx[MAX];

void pre(int start, int end, int post_start, int post_end) {
	if(start > end || post_start > post_end) return;
	
	int root = post[post_end];
	
	cout << root << ' ';
	int idx = inidx[root] - start;
	pre(start, inidx[root] - 1, post_start, post_start + idx - 1);
	pre(inidx[root] + 1, end, post_start + idx, post_end-1);
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		cin >> in[i];
	}
	
	for (int i=0; i<n; i++) {
		cin >> post[i];
	}
	for (int i=0; i<n; i++) {
		inidx[in[i]] = i;
	}
	
	pre(0, n-1, 0, n-1);
	
}
