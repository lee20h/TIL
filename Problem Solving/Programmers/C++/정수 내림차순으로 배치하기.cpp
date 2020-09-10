#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector<long long> answer;
    while(n) {
        answer.push_back(n%10);
        n/=10;
    }
    sort(answer.begin(),answer.end());
    long long ans = 0;
    for (int i=0; i<answer.size(); i++) {
        ans += answer[i] * pow(10,i);
    }
    return ans;
}
