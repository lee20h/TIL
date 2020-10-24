#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void div(int size, int y, int x, vector<int> &answer) {
	bool zero = true, one = true;
	for (int i=y; i<y+size; i++) {
		for (int j=x; j<x+size; j++) {
			if(v[i][j])
				zero = false;
			else if(!v[i][j])
				one = false;
		}
	}
	if(zero) {
		answer[0]++;
		return;
	}
	if(one) {
		answer[1]++;
		return;
	}
	
	div(size/2, y, x, answer);
	div(size/2, y+size/2, x, answer);
	div(size/2, y, x+size/2, answer);
	div(size/2, y+size/2, x+size/2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    v = arr;
    div(arr.size(), 0, 0, answer);
    return answer;
}
