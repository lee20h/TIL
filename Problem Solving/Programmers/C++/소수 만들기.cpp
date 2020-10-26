#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(!n || n==1)
        return false;
    for (int i=2; i<n/2; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int len = nums.size();
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            for (int k=j+1; k<len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if(isPrime(sum))
                    answer++;
            }
        }
    }
    return answer;
}
