#include <string>
#include <vector>

using namespace std;

const int MAX = 1e6+1;
bool PrimeArray[MAX];

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
	}
    
    for (int i=2; i<=n; i++) {
        if(PrimeArray[i])
            answer++;
    }
    return answer;
}
