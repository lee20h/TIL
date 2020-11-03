#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<string,pair<string,int>> a, pair<string, pair<string,int>> b){
	if(a.first == b.first) {
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        return stoi(a.second.first) < stoi(b.second.first);
    }
    else
        return a.first < b.first;

}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, pair<string,int>>> v;
    for (int i=0; i<files.size(); i++) {
        string temp = files[i];
        bool headflag = false;
        bool numflag = false;
        string head, number, tail;
        for (int j=0; j<temp.length(); j++) {
            if(isdigit(temp[j]))
                headflag = true;
            if(!headflag)
                head += tolower(temp[j]);
            else {
                if(!isdigit(temp[j]))
                    numflag = true;
                if(!numflag)
                    number += temp[j];
                else
                	break;
            }
        }
        v.push_back({head,{number,i}});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for (int i=0; i<v.size(); i++) {
        answer.push_back(files[v[i].second.second]);
    }
    return answer;
}
