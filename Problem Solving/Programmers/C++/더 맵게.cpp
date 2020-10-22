#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.size() >= 2 && pq.top() < K) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        pq.push(first + (2*second));
        answer++;
    }
    if(pq.top() < K)
        return -1;
    else
        return answer;
}
