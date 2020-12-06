#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int N, int number) {
    int answer = 0; 
    if(N == number) {
        return 1;
    }
    vector<set<int>> arr(8);
    for(int i=0; i<8; i++){
        int n = N;
        int cnt = i;
        while(cnt > 0){
            cnt--;
            n *= 10;
			n += N;
        }
        arr[i].insert(n);
    }
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(auto x : arr[j]){
                for(auto y : arr[i-j-1]){
                    arr[i].insert(x+y);
                    arr[i].insert(x*y);
                    arr[i].insert(x-y);
                    if(y)
                        arr[i].insert(x/y);
                }
            }
        }
        if(arr[i].find(number) != arr[i].end()){
            return i+1;
        }
    }
    return -1;
}
