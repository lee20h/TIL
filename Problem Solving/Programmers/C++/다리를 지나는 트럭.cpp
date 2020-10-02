#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q, bridge;
    int total_weight = 0;
    while(1) {
        int size = bridge.size();
        for (int i=0; i<size; i++) {
            int len = bridge.front();
            bridge.pop();
            len--;
            if(len == 0) {
                total_weight -= q.front();
                q.pop();
                continue;
            }
            bridge.push(len);
        }
        
        if(truck_weights.size() && total_weight + truck_weights[0] <= weight) {
            total_weight += truck_weights[0];
            bridge.push(bridge_length);
            q.push(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(!truck_weights.size() && !q.size())
            break;
    }
    return answer;
}
