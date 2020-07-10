#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for (int i=0; i<priorities.size(); i++) {
        q.push(make_pair(priorities[i],i));
        pq.push(priorities[i]);
    }
    int cnt = 0;
    while(!q.empty()) {
        if(q.front().first == pq.top()) {
            if(q.front().second == location)
                return answer;
            else {
                answer++;
                pq.pop();
                q.pop();
            }
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}
