#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num1, num2;
	char op;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> num1 >> num2;
		if (num1 > num2)
			cout << "#" << test_case << ' ' << ">" << '\n';
		else if (num1 == num2)
			cout << "#" << test_case << ' ' << "=" << '\n';
		else
			cout << "#" << test_case << ' ' << "<" << '\n';
	}
	return 0;
}
