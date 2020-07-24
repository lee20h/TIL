#include <bits/stdc++.h>
using namespace std;

const int empty = -1;
int v[26][2];

void preorder(int node) {
	if(node == empty) return;
	cout << (char)(node + 'A');
	preorder(v[node][0]);
	preorder(v[node][1]);
}
void innerorder(int node) {
	if(node == empty) return;
	innerorder(v[node][0]);
	cout << (char)(node + 'A');
	innerorder(v[node][1]);
}

void postorder(int node) {
	if(node == empty) return;
	postorder(v[node][0]);
	postorder(v[node][1]);
	cout << (char)(node + 'A');
}
int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		char p, c, c2;
		cin >> p >> c >> c2;
		c != '.' ? v[p-'A'][0] = c - 'A': v[p-'A'][0] = empty;
		c2 != '.'? v[p-'A'][1] = c2 - 'A' : v[p-'A'][1] = empty;
	}
	preorder(0);
	cout << '\n';
	innerorder(0);
	cout << '\n';
	postorder(0);
	
} 
