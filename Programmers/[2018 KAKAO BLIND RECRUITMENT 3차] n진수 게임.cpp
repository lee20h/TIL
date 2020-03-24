#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> v;
    char c[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int num = t*m;
    int su;
    string temp;
    for (int i=0; i<num; i++) {
    	su = i;
    	if(i==0) v.push_back('0');
    	if(i<n) {
    		while(su) {
    			v.push_back(c[su%n]);
    			su = su / n;
			}
		}
    	else {
    		while(su) {
    			temp = c[su%n] + temp;	
    			su = su / n;
			}
			for (int j=0; j<temp.length(); j++)
				v.push_back(temp[j]);
		}
		temp.clear();
	}
	int cnt = 1;
	for (int i=0; i<num; i++) {
		if(cnt==m+1) cnt = 1;
		if(cnt==p) answer+=v[i];
		cnt++;
	}
    return answer;
}
