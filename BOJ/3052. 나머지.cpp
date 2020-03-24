#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a;
	vector<int> v;
	for (int i=0; i<10; i++) {
		cin >> a;
		v.push_back(a%42);
		for (int j=0; j<v.size()-1;j++){
			if(v[j]==a%42) {
				v.erase(v.begin()+v.size()-1);
			}
		}
	}
	cout << v.size();
}
