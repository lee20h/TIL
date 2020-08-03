#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll  x, ll y, ll mod) // ºÐÇÒÁ¤º¹À¸·Î °ÅµìÁ¦°ö
{
	ll ret = 1;
	while (y > 0)
	{
		if (y % 2)
		{
			ret *= x;
			ret %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
    return ret;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << pow(a,b,c);
}
