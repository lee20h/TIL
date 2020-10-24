#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    sort(citations.begin(), citations.end());
    int size = citations.size();
    for (int i=0; i<size; i++) {
        if(citations[i] >= answer)
            break;
        answer--;
    }
    return answer;
}
