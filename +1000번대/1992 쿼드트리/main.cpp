#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int board[65][65];

bool check(int fx, int fy, int lx, int ly)
{
    int flag = board[fy][fx];
    for (size_t sy = fy; sy <= ly; ++sy)
    {
        for (size_t sx = fx; sx <= lx; ++sx)
        {
            if (board[sy][sx] != flag)
                return false;
        }
    }
    return true;
}

void partition(int fx, int fy, int lx, int ly)
{
    bool flag = false;
    if (fx == lx && fy == ly)
    {
        cout << board[fy][fx];
        return;
    }

    if (check(fx, fy, lx, ly))
    {
        flag = true;
    }

    if (flag && board[fy][fx] == 0)
    {
        cout << 0;
    }
    else if (flag && board[fy][fx] == 1)
    {
        cout << 1;
    }
    else
    {
        cout << "(";

        int mx = (fx + lx) / 2;
        int my = (fy + ly) / 2;

        partition(fx, fy, mx, my);
        partition(mx + 1, fy, lx, my);
        partition(fx, my + 1, mx, ly);
        partition(mx + 1, my + 1, lx, ly);

        cout << ")";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (size_t i = 1; i <= N; ++i)
    {
        string str;
        cin >> str;

        for (size_t j = 1; j <= N; ++j)
        {
            board[i][j] = str[j - 1] - '0';
        }
    }

    partition(1, 1, N, N);

    return 0;
}