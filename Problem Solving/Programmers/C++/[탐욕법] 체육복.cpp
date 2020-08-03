#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int arr[30];
    int answer = 0;
    for (int i=0; i<n; i++) arr[i] = 1;
    for (int i=0; i<lost.size(); i++) {
        arr[lost[i]-1]--;
    }
    for (int i=0; i<reserve.size(); i++) {
        arr[reserve[i]-1]++;
    }
    
    for (int i=0; i<n; i++) {
        if(arr[i] == 2) {
            if(i==0) {
                if(arr[1] == 0) {
                    arr[0]--;
                    arr[1]++;
                }
            }
            else if(i==n-1) {
                if(arr[n-2] == 0) {
                    arr[n-1]--;
                    arr[n-2]++;
                }
            }
            else {
                if(arr[i-1] == 0) {
                    arr[i]--;
                    arr[i-1]++;
                }
                else if(arr[i+1] == 0) {
                    arr[i]--;
                    arr[i+1]++;
                }
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if(arr[i] > 0) answer++;
    }
    return answer;
}
