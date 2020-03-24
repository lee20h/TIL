#include <string>
#include <vector>
using namespace std;

int count;

void dfs(vector<int> number, int sum, int target, int idx) {
	if(idx==number.size()) {
		if(sum == target) {
			count++;
		}
		return;
	}
	dfs(number, sum+number[idx], target, idx+1);
	dfs(number, sum-number[idx], target, idx+1);
}




int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers,numbers[0],target, 1);
    dfs(numbers,-1*numbers[0],target, 1);
    answer = count;
    
    
    return answer;
}
