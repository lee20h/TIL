#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    vector<int> v;
    for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			for (int k=1; k<=9; k++) {
				if(i==j || j==k || i==k) continue;
				int num = i*100 + j*10 + k;
				v.push_back(num);
			}
		}
	}
	
	for (int i=0; i<baseball.size(); i++) {
		int num, str, ball;
        num = baseball[i][0];
        str = baseball[i][1];
        ball = baseball[i][2];
		
		int one, ten, hund;
		one = num % 10;
		ten = (num / 10) % 10;
		hund = num / 100;
		vector<int> temp;
		for (int i=0; i<v.size(); i++) {
			int o, t, h;
			o = v[i] % 10;
			t = (v[i] / 10) % 10;
			h = v[i] / 100;
			int s = 0, b = 0;
			if(o == one)
				s++;
			else if(o == ten)
				b++;
			else if(o == hund)
				b++;
				
				
			if(t == one)
				b++;
			else if(t == ten)
				s++;
			else if(t == hund)
				b++;
				
				
			if(h == one)
				b++;
			else if(h == ten)
				b++;
			else if(h == hund)
				s++;
				
			if(str == s && ball == b) {
				temp.push_back(v[i]);
			}
		}
		v.clear();
		for (int i=0; i<temp.size(); i++) {
			v.push_back(temp[i]);
		}
	}
    return v.size();
}
