#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T;
	int num;
	cin >> T;
	int temp;
	int list[T];
	for(int i = 0; i < T; i++)
	{
		cin >> num;
		list[i] = num;
	}
	
	for (int i=T-1; i<T; i--) {
		for (int j=0; j<i; j++) {
			if (list[j]<list[j+1]) {
				temp = list[j+1];
				list[j+1] = list[j];
				list[j] = temp;
			}
		}
	}
	int length = T;
	cout << list[length/2];
	return 0;
}
