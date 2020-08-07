#include <bits/stdc++.h>
using namespace std;

char str1[3027];
char str2[3027];
int board[1005][1005];

bool check(int i, int j) {
	if (str1[i * 3] == str2[j * 3] && str1[i * 3 + 1] == str2[j * 3 + 1] && str1[i * 3 + 2] == str2[j * 3 + 2]) return true;
	return false;
}

int main() {
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1) / 3;
	int len2 = strlen(str2) / 3;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (check(i - 1, j - 1)) board[i][j] = board[i - 1][j - 1] + 1;
			else board[i][j] = max(board[i - 1][j], board[i][j - 1]);
		}
	}
	printf("%d", board[len1][len2]);
	return 0;
}
