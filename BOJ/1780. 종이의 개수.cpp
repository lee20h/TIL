#include <iostream>
using namespace std;
#define MAX_N 2188

int N;
int paper[MAX_N][MAX_N];
int cnt[3];

bool same(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n)
{
    if (same(x, y, n))
    {
        cnt[paper[x][y] + 1] += 1;
        return;
    }
    int m = n / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solve(x+i*m, y+j*m, m);
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);
    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
    return 0;
}
