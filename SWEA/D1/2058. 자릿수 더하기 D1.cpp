#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int num;
    cin >> num;
    int sum=0;
    int pivot=1000;
    while(pivot>0) {
    	sum += num / pivot;
    	num = num % pivot;
    	pivot/=10;
    }
    cout << sum;
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
