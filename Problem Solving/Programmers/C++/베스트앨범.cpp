#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    map<int, string> rev;
    int len = genres.size();
    
    for (int i=0; i<len; i++) {
        m[genres[i]] += plays[i];
    }
    int a = 0;
    string s;
    for (auto it = m.begin(); it != m.end(); it++) {
        rev[-(it->second)] = it->first;
    }
    
    for (auto it = rev.begin(); it != rev.end(); it++) {
        vector<pair<int,int>> v;
        for (int i=0; i<genres.size(); i++) {
            if(genres[i] == it->second) {
                v.push_back({-(plays[i]),i});
            }
        }
        sort(v.begin(),v.end());
        if(v.size() == 1)
            answer.push_back(v[0].second);
        else {
            answer.push_back(v[0].second);
            answer.push_back(v[1].second);
        }
    }
    
    return answer;
}
