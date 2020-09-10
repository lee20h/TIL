#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string mon[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int d[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 0;
    for (int i=1; i<a; i++) {
        day  += d[i];
    }
    day += b;
    day = day % 7 -1;
    day < 0 ? day = 6 : 1;
    answer = mon[day]; 
    return answer;
}
