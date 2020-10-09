#include <string>
#include <cstring>
#include <vector>
using namespace std;
int table[1002][1002];

vector<int> solution(int n) {
	vector<int> answer;
    memset(table, -1, sizeof(table));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			table[i][j] = 0;
		}
	}
	int cnt = 1;
	int y = 1, x = 1;
	while(1) {
		bool flag = true;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y++][x] = cnt++;
			flag = false;
		}
		y--;
		x++;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y][x++] = cnt++;
			flag = false;
		}
		x-=2;
		y--;
		while(1) {
			if(table[y][x] != 0)
				break;
			table[y--][x--] = cnt++;
			flag = false;
		}
		x++;
		y+=2;
		if(flag)
			break;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
            if(table[i][j] == -1 || !table[i][j])
                continue;
			answer.push_back(table[i][j]);
		}
	}
    return answer;
}
