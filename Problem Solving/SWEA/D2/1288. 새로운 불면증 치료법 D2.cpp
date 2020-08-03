#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> answer;
	string str;
	int num;
	int count;
	int num2;
	for (int test=1; test<=t; test++) {
		count = 0;
		answer.clear();
		cin >> num;
		answer.push_back(num%10);
		while(1) {
			if(answer.size()==10)
				break;
			count++;
			num2 = num * count;
			str = to_string(num2);
			for (int i=0; i<str.length(); i++) {
				string temp;
				int a;
				temp = str.substr(i,1);
				a = atoi(temp.c_str());
				for (int j=0; j<answer.size(); j++) {
					if(answer[j]==a) {
						break;
					}
					if(j==answer.size()-1)
						answer.push_back(a);
				}
			}
		}
		cout << "#" << test << ' ' << num2 << '\n';
	}
	return 0;
}
