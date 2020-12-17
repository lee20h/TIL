#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0, begin = 0;
    vector<pair<int,int>> v;
    for (int i=0; i<jobs.size(); i++)
        v.push_back({jobs[i][0], jobs[i][1]});
    
    sort(v.begin(), v.end(), cmp);
    
    while(!v.empty()) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].first <= begin) {
                begin += v[i].second;
                time += begin - v[i].first;
                v.erase(v.begin() + i);
                break;
            }
            if(i == v.size()-1)
                begin++;
        }
    }
    return answer = time / jobs.size();
}
