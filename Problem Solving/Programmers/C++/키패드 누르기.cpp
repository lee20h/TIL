#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    for (int i=0; i<numbers.size(); i++) {
    	if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
    		answer += 'L';
    		left = numbers[i];
		}
		else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += 'R';
			right = numbers[i];
		}
		else {
            if(numbers[i] == 0)
                numbers[i] = 11;
            int tempRight = abs(right - numbers[i]);
            int tempLeft = abs(left - numbers[i]);
            int distRight = (tempRight/3) + (tempRight%3);
            int distLeft = (tempLeft/3) + (tempLeft%3);
            
			if(distLeft > distRight) {
				answer += 'R';
				right = numbers[i];
			}
			else if (distLeft < distRight) {
				answer += 'L';
				left = numbers[i];
			}
			else {
				if(hand == "right") {
					answer += 'R';
					right = numbers[i];
				}
				else {
					answer += 'L';
					left = numbers[i];
				}
			}
		}
	}
    return answer;
}
