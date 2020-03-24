#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> pic;
bool flag[101][101];
int a, b;
int pos[4] = {1,-1,0,0};
int pos2[4] = {0,0,1,-1};
int area_size;
int size;
void bfs(int s, int g) {
	int count = 0; //블록의 갯수 
	queue<pair<int,int>> que;
	pair<int,int> p;
	que.push({s,g});
	
	flag[s][g] = true;
	int garo;
	int sero;
	while (!que.empty()) {
		p = que.front();
		que.pop();
		count++;
		for (int i=0; i<4; i++) {
			garo = p.second + pos[i];
			sero = p.first + pos2[i];
			if(sero < 0 || sero > a-1 || garo < 0 || garo > b-1) continue;
		if(pic[sero][garo] != pic[p.first][p.second]) continue;
		if(!flag[sero][garo]) {
			que.push({sero, garo});
			flag[sero][garo] = true;
		}
		}
		
	}
	area_size = max(area_size,count);
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
	area_size = 0;
	size = 0;
    a = m; 
    b = n;
    pic = picture;
    for (int i=0; i<m; i++) {
    	for(int j=0; j<n; j++) {
    		flag[i][j] = false;    
		}
	}
	for (int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if (!flag[i][j] && pic[i][j] != 0){
				bfs(i,j);
				size++;
			}
				
		}
	}
    
    number_of_area = size;
    max_size_of_one_area = area_size;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
