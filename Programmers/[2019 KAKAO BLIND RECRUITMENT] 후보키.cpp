#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int row = relation.size();
    int col = relation[0].size();
    bool unique[col] = {false,};
    set<string> s;
    
    while(1) {
    	for (int i=0; i<col; i++) {
    		for (int j=0; j<row; j++) {
    			if(unique[i])
    			for (int k=j; l<row; k++) {
    				
				}
			}
		}
	}
    
    return answer;
}
