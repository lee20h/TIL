#include<iostream>
#include<stack>
using namespace std;

int main() {
	int k;
	cin >> k;
	stack<int> st;
	int n;
	for (int i=0; i<k; i++) {
		cin >> n;
		if(n==0) {
				st.pop();
			}
		else {
			st.push(n);
		}
	}
		
	
	int sum = 0;
	for (int i=0; !st.empty(); i++) {
		sum += st.top();
		st.pop();
	}
	cout << sum; 
} 
