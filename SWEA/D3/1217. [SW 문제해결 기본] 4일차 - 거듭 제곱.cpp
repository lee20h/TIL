#include <bits/stdc++.h>
using namespace std;

int pow(int x, int y) // ºÐÇÒÁ¤º¹À¸·Î °ÅµìÁ¦°ö
{ 
	int ret = 1;
	while (y > 0)
	{
		if (y % 2)
		{
			ret *= x;
		}
		x *= x;
		y /= 2;
	}
    return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int temp;
	for (int t=1; t<=10; t++) {
		cin >> temp;
		int n, m;
		cin >> n >> m;
		cout << "#" << t << ' ' << pow(n,m) << '\n';
	}
}
