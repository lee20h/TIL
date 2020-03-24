#include <iostream>
using namespace std;

int main() {
	int angle[3];
	int sum = 0;
	int prev=0;
	int count=0;
	for (int i=0; i<3; i++) {
		cin >> angle[i];
		sum += angle[i];
	}
	for (int i=0; i<3; i++) {
		for (int j=i+1; j<3; j++) {
			if(angle[i]==angle[j]) count++;
		}
	}
	if(angle[0] == 60 && angle[1] == 60 && angle[2] == 60) cout << "Equilateral";
	else if(count==1 && sum==180) cout << "Isosceles";
	else if(count==0 && sum==180) cout << "Scalene";
	else cout << "Error";
	
}
