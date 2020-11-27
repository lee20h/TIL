#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<pair<string, int>> v;
    for (int i=0; i<m.length(); i++) {
        if(m[i] == '#') {
            string temp;
            temp += tolower(m[i-1]);
            string str = m.substr(0, i-1) + temp + m.substr(i+1);
            m = str;
        }
    }
    
    for (int i=0; i<musicinfos.size(); i++) {
        string start, end, title, music;
        start = musicinfos[i].substr(0, 5);
        end = musicinfos[i].substr(6, 5);
        
        bool flag = false;
        for (int j=12; j<musicinfos[i].length(); j++) {
            if(musicinfos[i][j] == ',') {
                flag = true;
                continue;
            }
            if(!flag) {
                title += musicinfos[i][j];
            }
            else {
                music += musicinfos[i][j];
            }
        }
        
        for (int j=0; j<music.length(); j++) {
            if(music[j] == '#') {
                string temp;
                temp += tolower(music[j-1]);
                string str = music.substr(0, j-1) + temp + music.substr(j+1);
                music = str;
            }
        }
        
        int begin = stoi(start.substr(0,2)) * 60 + stoi(start.substr(3));
        int last = stoi(end.substr(0,2)) * 60 + stoi(end.substr(3));
        // if(last == 0) {
        //     last = 24 * 60;
        // }
        int runtime = last - begin;
        string total_music = music;
        while(runtime > total_music.length()) 
            total_music += music;
        while(runtime < total_music.length())
             total_music.pop_back();
        
        if(total_music.find(m) != string::npos) {
            v.push_back({title, runtime});
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    if(!v.empty())
        answer = v[0].first;
    else
        answer = "(None)";
    return answer;
}
