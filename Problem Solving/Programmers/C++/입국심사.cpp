#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    int size = times.size();
    long long M = (long long)times.back() * n;
    long long m = 1;
    long long mid;
    long long sum;
    answer = M;
    while(m <= M) {
        mid = (M + m) / 2;
        sum = 0;
        for(int i=0; i<size; i++) 
            sum += mid / times[i];
        
        if(sum < n)
            m = mid + 1;
        else {
            if(mid <= answer)
                answer = mid;
            M = mid - 1;
        }
    }
    return answer;
}
