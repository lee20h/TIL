#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10001];

void sol(int left, int right) {
	if(left > right) return;
	
	int root = left, left_part = left, right_part = right;
	
	while(arr[left_part] >= arr[root]) left_part++;
	while(arr[right_part] > arr[root]) right_part--;
	
	sol(left_part,right_part);
	sol(right_part+1,right);
	cout << arr[root] << '\n';
	
}

int main() {
	int x;
	while (scanf("%d", &x) != EOF) {
		arr[n++] = x;
	}
	sol(0, n-1);
}
