#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int left[1000001], right[1000001];

int solution(vector<int> a) {
    int answer = 0;
    left[0] = a[0];
    right[a.size()-1] = a[a.size()-1];
    for(int i=1; i<a.size(); i++)
        left[i] = min(left[i-1],a[i]);
    for(int j=a.size()-2; j>=0; j--)
        right[j] = min(right[j+1],a[j]);
        
    if(a.size()<3)
		answer = a.size();
    else {
        answer = 2;
        for(int i=1; i<a.size()-1; i++)
            if(!(a[i]>left[i-1] && a[i]>right[i+1]))
				answer++;
    }
    return answer;
}
