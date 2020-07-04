#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b) {
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
} 

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int mo; 
    vector<pair<double, int> > rate;
    int ja;
    for (int i=1; i<=N; i++) {
    	mo=ja=0;
    	for (int j=0; j<stages.size(); j++) {
    		if(stages[j]>=i) {
    			mo++;
			}
			if(stages[j]==i) {
				ja++;
			}
		}
		if(mo!=0)
		rate.push_back(make_pair((double)ja/mo,i));
		else {
			rate.push_back(make_pair(0,i));
		}
	}
    
    sort(rate.begin(),rate.end() ,compare);
    for (int i=0; i<rate.size();i++) {
    	answer.push_back(rate[i].second);
	}
    
    return answer;
    
}
