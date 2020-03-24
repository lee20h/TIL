#include <iostream> 
#include <string>

using namespace std;

int num(int a) {
	int r = 0;
	while(a>0) {
		a = a/10;
		r++;
	}
	return r;
}

int solution(string s) {
    int answer = 9999999;
    int answer_ = s.size();
    string temp;
    int count;
    if (s.size() == 1)
    	return 1;
    for (int i=1; i<=s.length()/2; i++) {
    	temp = s.substr(0,i);
    	count = 1;
    	answer_ = 0;
    	
    	for (int j=i; j<s.length(); j += i) {
    		if(temp == s.substr(j,i)) 
    			count++;
			else {
				if(count > 1) {
					count = num(count);
					answer_ += count;
				}
				answer_ += i;
				count = 1;
				temp = s.substr(j,i);
			}
			
			if(i+j>=s.size()) {
				if(count>1) {
					count = num(count);
					answer_ += count;
				}
				answer_ += (s.size() - j);
			}
		}
		
		answer = min(answer,answer_);
	}
    return answer;
}
