#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gettime(string line) {
    int h = stoi(line.substr(11,2)) * 60 * 60 * 1000;
    int m = stoi(line.substr(14,2)) * 60 * 1000;
    int s = stoi(line.substr(17)) * 1000 + stoi(line.substr(20));
    return h + m + s;
}

int getduring(string line) {
    int sec = stod(line.substr(24)) * 1000;
    return sec;
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<int> endTime;
    vector<int> duringTime;
    for (int i=0; i<lines.size(); i++) {
        endTime.push_back(gettime(lines[i]));
        duringTime.push_back(getduring(lines[i]));
    }
    
    int start, range;
    for(int i=0; i<lines.size(); i++) {
        int cnt = 1;
        range = endTime[i] + 1000;
        for (int j=i+1; j<lines.size(); j++) {
            start = endTime[j] - duringTime[j] + 1;
            if(start < range)
                cnt++;
        }
        if (answer < cnt)
            answer = cnt;
    }
    return answer;
}
