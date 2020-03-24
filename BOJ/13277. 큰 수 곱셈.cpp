#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
using namespace std;

string plus_string(string a, string b) {
	string ans = "";

	int ai = a.length() - 1;
	int bi = b.length() - 1;

	bool over = false;
	while (ai != -1 && bi != -1) {
		int c = a[ai] - '0';
		int d = b[bi] - '0';

		if (over)
			++c;
		over = false;
		if (c + d > 9)
			over = true;
		ans = to_string((c + d) % 10) + ans;
		--ai;
		--bi;
	}

	if (ai >= 0) {
		while (ai != -1) {
			int c = a[ai] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--ai;
		}
	}
	else if (bi >= 0) {
		while (bi != -1) {
			int c = b[bi] - '0';
			if (over)
				++c;
			over = false;
			if (c > 9)
				over = true;

			ans = to_string(c % 10) + ans;
			--bi;
		}
	}

	if (over)
		ans = "1" + ans;

	return ans;
}

string multi_string(string a, int i) {
	string ans = "";

	int ai = a.length() - 1;

	int over = 0;
	while (ai != -1) {
		int c = a[ai] - '0';

		int prev_over = over;
		over = (c * i + prev_over) / 10;

		ans = to_string((c * i + prev_over) % 10) + ans;
		--ai;
	}

	if (over != 0)
		ans = to_string(over) + ans;

	return ans;
}

string multi_string_plus(string a, string b) {
	string ans = "0";

	int len = b.length();
	int cnt = 0;
	while (len > 0) {
		string temp = multi_string(a, b[len - 1] - '0');
		for (int i = 0; i < cnt; ++i)
			temp += "0";
		ans = plus_string(ans, temp);
		++cnt;
		--len;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	cout << multi_string_plus(a, b) << endl;
	return 0;
}
