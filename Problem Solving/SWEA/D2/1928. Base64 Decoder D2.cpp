#include <iostream>
#include <bitset>
using namespace std;

int convert(char a) {
	if (a>='A' && a<='Z') {
		return a-65;
	}
	else if (a>='a' && a<='z') {
		return a-71;
	}
	else if (a>='0' && a<='9') {
		return a+4;
	}
	else if (a==' '){
		return a+30;
	}
	else if (a=='/') {
		return a+16;
	}
}


int main() {
	int t;
	cin >> t;
	bitset<8> bit1;
	bitset<8> bit2;
	string question;
	string answer;
	char a;
	int b;
	
	for (int test=1; test<=t; test++) {
		cin >> question;
		answer.clear();
		for (int i=0; i<question.length(); i+=4) {
			if (i%4==0) {
				b = convert(question[i]);
				bit1 = b;
				bit1 <<= 2;
				b = convert(question[i+1]);
				bit2 = b;
				bit2 >>= 4;
				bit1 = bit1 |= bit2;
				a = bit1.to_ulong();
				
				answer += a;
				
				b = convert(question[i+1]);
				bit1 = b;
				bit1 <<= 4;
				b = convert(question[i+2]);
				bit2 = b;
				bit2 >>= 2;
				bit1 = bit1 |= bit2;
				a = bit1.to_ulong();
				
				answer += a;
				
				b = convert(question[i+2]);
				bit1 = b;
				bit1 <<= 6;
				b = convert(question[i+3]);
				bit2 = b;
				bit1 = bit1 |= bit2;
				a = bit1.to_ulong();
				answer += a;
			}
		}
		cout << "#" << test << ' ' << answer << '\n';
	}
	return 0;
	
}
