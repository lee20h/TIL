#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int convert(string hour, string min) {
    int h = stoi(hour) * 60;
    int m = stoi(min);
    return h + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> crew;
    for (int i=0; i<timetable.size(); i++) {
        string str = timetable[i];
        string hour = str.substr(0,2);
        string min = str.substr(3,2);
        crew.push_back(convert(hour,min));
    }
    sort(crew.begin(),crew.end());
    
    int start = 540;
    int ans, idx = 0;
    
    for (int i=0; i<n; i++) {
        int size = m;
        for (int j=idx; j<crew.size(); j++) {
            if(crew[j] <= start)
                idx++, size--;
            if(size == 0)
                break;
        }
        
        if(i == n-1) {
            if(size == 0) {
                ans = crew[idx-1]-1;
            }
            else {
                ans = start;
            }
        }
        start += t;
        if(start >= 24 * 60)
                break;
    }
    
    int hour = ans/60;
    int min = ans%60;
    if(hour < 10)
        answer = "0" + to_string(hour);
    else
        answer = to_string(hour);
    answer += ":";
    if(min < 10)
        answer += "0" + to_string(min);
    else
        answer += to_string(min);
    
    
    return answer;
}
