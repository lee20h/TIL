#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    int Sum = 0;
    for (int i=0; i<numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
        Sum += numbers[i];
    }
    if(!Sum)
        return "0";
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<v.size(); i++)
        answer += v[i];
    return answer;
}
