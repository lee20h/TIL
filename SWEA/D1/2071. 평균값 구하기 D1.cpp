#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int sum;
    int num;
    double result;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		sum=0;
		for (int i=0; i<10; i++) {
        	cin >> num;
            sum+=num;
        }
        result = (double(sum)/10);
		cout << "#" << test_case << ' ' << round(result) << '\n';
	}
	return 0;
}
