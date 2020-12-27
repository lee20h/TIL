#include <vector>
using namespace std;

int getCenter(int emptyCenter, int w) {
	if(emptyCenter > 0) {
		int q, r;
		q = emptyCenter / (2*w+1);
		r = emptyCenter % (2*w+1);
		if(r)
			return q+1;
		else
			return q;
	}
	else 
		return 0;
}

int solution(int n, vector<int> stations, int w) {
    int answer = 0, emptyCenter;
    
    emptyCenter = stations[0] - w - 1;
    answer += getCenter(emptyCenter, w);
    
    for (int i=1; i<stations.size(); i++) {
    	int before = stations[i-1];
    	int current = stations[i];
    	emptyCenter = (current - w - 1) - (before + w + 1) + 1;
    	answer += getCenter(emptyCenter, w);
	}
	
	emptyCenter = n - (stations[stations.size()-1] + w + 1) + 1;
	answer += getCenter(emptyCenter, w);

    return answer;
}

