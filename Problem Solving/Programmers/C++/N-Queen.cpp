#include <string>
#include <vector>

using namespace std;

int col[12];

bool promising(int i) {
    for(int j=0;j<i;j++)
    {
        if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
            return false;
    }
    return true;
}

int nQueen(int i, int n) {
    int result = 0;
    if(i == n)
        result += 1;
    else
    {
        for(int j=0;j<n;j++)
        {
            col[i] = j;
            if(promising(i))
                result += nQueen(i+1, n);
        }
    }
    return result;
}

int solution(int n) {
    int answer = nQueen(0, n);
    return answer;
}
