#include <string>
#include <vector>
#include <stack>
using namespace std;

bool correc(string s) {
	stack<int> a;
	for (int i=0; i<s.length(); i++) {
		if(s[i] == '(')
			a.push(s[i]);
		else if (s[i] == ')') {
			if(a.empty()) {
				return false;
				break;	
			}
			a.pop();
		}
	}
	return true;
}

string solution(string p) {
    string answer = "";
    if(p.empty()) {
    	return answer;
	}
	bool correct;
	string u, v, temp;
	u = v = temp = "";
	int left=0, right=0;
	correct = correc(p);
	if(correct) {
		answer = p;
		return answer;
	}
	for (int i=0; i<p.length(); i++) {
		if (p[i] == '(') {
			left++;
		}
		else if (p[i] == ')') {
			right++;
		}
		u += p[i];
		if (left==right)
			break;
	}
	
	for (int i=right+left; i<p.length(); i++) {
		 v += p[i];
	}
	
	correct = correc(u);
	
	if (correct) {
		u += solution(v);
		answer = u;
		return answer;
	}
	else {
		temp += '(';
		temp += solution(v);
		temp += ')';
		u = u.substr(1,u.length()-2);
		for (int i=0; i<u.length(); i++) {
			if (u[i] == '(') {
				u[i] = ')';
			}
			else if (u[i] == ')') {
				u[i] = '(';
			}
		}
		temp += u;
		answer = temp;
		return answer;
	}
}
