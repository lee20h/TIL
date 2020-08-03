#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	int count;
	int sero, garo;
	int lt, rt, lb, rb;
	int value;
	int array[10][10];
	for (int test = 1; test<=t; test++) {
		cin >> n;
		rt = rb = n;
		lt = lb = 0;
		value=1;
		sero = garo = 0;
		while(value!=n*n+1) {
			while(rt>garo){
				array[sero][garo++] = value;
				value++;
			}
			garo--;
			sero++;
			rt--;
			while(rb>sero){
				array[sero++][garo] = value;
				value++;
			}
			sero--;
			garo--;
			rb--;
			while(lb<=garo) {
				array[sero][garo--] = value;
				value++;
			}
			garo++;
			sero--;
			lb++;
			while(lt<sero) {
				array[sero--][garo] = value;
				value++;
			}
			sero++;
			garo++;
			lt++;
		}
		cout << "#" << test << '\n';
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << array[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
