#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int aidx = 0;
    int bidx = 0;
    
    if(A[A.size()-1] > B[0]) return 0;
    
    for (int i=0; i<A.size(); i++) {
        if(A[aidx] < B[bidx]) {
            answer++;
            bidx++;
        }
        aidx++;
    }
    return answer;
}
