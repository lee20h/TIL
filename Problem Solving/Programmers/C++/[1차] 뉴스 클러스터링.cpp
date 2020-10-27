#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v;
    vector<string> v2;
    for (int i=0; i<str1.length(); i++)
        str1[i] = tolower(str1[i]);
    for (int i=0; i<str2.length(); i++)
        str2[i] = tolower(str2[i]);
    
    for (int i=1; i<str1.length(); i++) {
        string temp;
        if(('a' <= str1[i-1] && str1[i-1] <= 'z') && ('a' <= str1[i] && str1[i] <= 'z')) {
            temp = str1.substr(i-1, 2);
            v.push_back(temp);    
        }
    }
    
    for (int i=1; i<str2.length(); i++) {
        string temp;
        if(('a' <= str2[i-1] && str2[i-1] <= 'z') && ('a' <= str2[i] && str2[i] <= 'z')) {
            temp = str2.substr(i-1, 2);
            v2.push_back(temp);    
        }
    }
    
    if(v.empty() && v2.empty()) {
        return 65536;
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    
    vector<string> uni(v.size() + v2.size());
    auto it = set_union(v.begin(),v.end(),v2.begin(),v2.end(),uni.begin());
    uni.erase(it,uni.end());
    vector<string> intersect(v.size() + v2.size());
    it = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), intersect.begin());
    intersect.erase(it, intersect.end());
    
    double temp = (double)intersect.size() / (double)uni.size();
    answer = temp * 65536;
    return answer;
}
