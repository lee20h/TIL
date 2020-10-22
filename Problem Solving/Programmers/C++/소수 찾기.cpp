#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 1e7;
bool isprime[MAX];


int solution(string numbers) {
    int answer = 0;
    isprime[0] = isprime[1] = true;
    for (int i=2; i<=10000; i++) {
        for (int j=2; i*j<=MAX; j++)
            isprime[i*j] = true;
    }
    sort(numbers.begin(),numbers.end());
    
    set<int> s;
    do {
    	int idx = 1;
    	while(idx <= numbers.size()) {
    		string str;
    		for (int i=0; i<idx; i++) {
    			str += numbers[i];
			}
    		s.insert(stoi(str));
            idx++;
		}	
	}while(next_permutation(numbers.begin(), numbers.end()));
	
    set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
        if(!isprime[*it])
            answer++;
    }
	
    return answer;
}
