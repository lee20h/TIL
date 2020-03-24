#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num;
	int maxi;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		maxi=0;
		for (int i=0; i<10; i++) {
			cin >> num;
			maxi = max(num,maxi);
		}
		cout << "#" << test_case << ' ' << maxi << '\n';
	}
	return 0;
}
