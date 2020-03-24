#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int sdo[9][9];
	int gsum, ssum, sum[3];
	bool wrong;
	for (int test=1; test<=t; test++) {
		gsum=0; ssum=0;
		for (int i=0; i<3; i++)
			sum[i] = 0;
		wrong = false;
		for (int i=0; i<9; i++)
			for (int j=0; j<9; j++)
				cin >> sdo[i][j];
		
		for (int i=0; i<9; i++){ 
			for (int j=0; j<9; j++) {
				gsum+=sdo[i][j];
				ssum+=sdo[j][i];
				
				if (j<3)
					sum[0]+=sdo[i][j];
				else if (j>=3 && j<6)
					sum[1]+=sdo[i][j];
				else
					sum[2]+=sdo[i][j];
				
			}
			if (gsum!=45 || ssum!=45) {
				wrong = true;
				break;
			}
			else if (i%3==2) {
				for(int k=0; k<3; k++) {
					if(sum[k] != 45)
						wrong = true;
				}
				for (int k=0; k<3; k++)
					sum[k] = 0;
			}
			gsum = 0;
			ssum = 0;
		}
		
		if(wrong)
			cout << "#" << test << ' ' << "0" << '\n';
		else
			cout << "#" << test << ' ' << "1" << '\n';
		
		
		
	}
	return 0;
}
