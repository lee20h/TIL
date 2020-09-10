#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int m = 987654321;
    for (int i=0; i<arr.size(); i++) {
        m = min(m,arr[i]);
    }
    for (int i=0; i<arr.size(); i++) {
        if(m != arr[i])
            answer.push_back(arr[i]);
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}
