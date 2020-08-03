#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(string d) {
    int answer = 0;
    vector<int> result(3);
    int count=0;
    string temp;
    int ten, one;
    int length = d.length();
	for (int i=0; i<length; i++) {
		
		if (d[i]=='S') {
			if(ten==1 && one==0) {
				result[count++] = 10;
				ten=9; one=9;
			}
			else {
				temp = d.substr(i-1,1);
				result[count++] = stoi(temp);	
			}
		}
		else if (d[i]=='D') {
			if(ten==1 && one==0) {
				result[count++] = 100;
				ten=9; one=9;
			}
			else {
				temp = d.substr(i-1,1);
				result[count++] = pow(stoi(temp),2);	
			}
		}
		else if (d[i]=='T') {
			if(ten==1 && one==0) {
				result[count++] = 1000;
				ten=9; one=9;
			}
			else {
				temp = d.substr(i-1,1);
				result[count++] = pow(stoi(temp),3);	
			}
		}
		else if (d[i]=='*') {
			if (count==1) {
				result[count-1] = result[count-1] * 2;
			}
			else {
				result[count-2] = result[count-2] * 2;
				result[count-1] = result[count-1] * 2;
			}
		}
		else if (d[i]=='#') {
			result[count-1] = result[count-1] * -1;
		}
		
		else if(d[i]=='1'&&d[i+1]=='0'){
			ten = 1; one = 0;
		}
	}
	
	for (int i=0; i<3;i++)
		answer += result[i];
    
    return answer;
}
