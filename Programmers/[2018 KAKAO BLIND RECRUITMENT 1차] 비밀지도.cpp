#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    bitset<16> bit1[n];
    bitset<16> bit2[n];
    string temp;
    for (int i=0; i<n;i++) {
    	bit1[i] = arr1[i];
    	bit2[i] = arr2[i];
    	bit1[i] = bit1[i] |= bit2[i];
	}
	for (int i=0; i<n; i++) {
		temp.clear();
		for (int j=0; j<n; j++) {
			if (bit1[i].test(j)) 
				temp = "#" + temp;
			else
				temp = " " + temp;
		}
		answer.push_back(temp);
	}
	
    return answer;
}
