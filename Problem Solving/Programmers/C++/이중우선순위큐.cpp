#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> d;
    for (int i=0; i<operations.size(); i++) {
        char cmd = operations[i][0];
        if(cmd == 'I') {
            string num;
            for(int j=2; j<operations[i].length(); j++) {
                num += operations[i][j];
            }
            int n = stoi(num);
            d.push_back(n);
            sort(d.begin(), d.end());
        }
        else if (cmd == 'D') {
            if(d.empty())
                continue;
            if(operations[i][2] == '-')
                d.pop_front();
            else
                d.pop_back();
        }
    }
    if(!d.empty()) {
        answer.push_back(d[d.size()-1]);
        answer.push_back(d[0]);
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
