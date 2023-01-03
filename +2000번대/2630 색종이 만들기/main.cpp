#include <iostream>

int board[129][129];
int N, blue, white;

bool check(int fx, int fy, int lx, int ly)
{
    bool flag = board[fy][fx];
    for (int sy = fy; sy <= ly; ++sy)
    {
        for (int sx = fx; sx <= lx; ++sx)
        {
            if (flag != board[sy][sx])
                return false;
        }
    }
    return true;
}

void partition(int fx, int fy, int lx, int ly)
{
    if (fx == lx && fy == ly)
    {
        if (board[fy][fx] == 1)
            blue++;
        else
            white++;
        return;
    }
    if ((fx < lx) && (fy < ly))
    {
        if (check(fx, fy, lx, ly))
        {
            if (board[fy][fx] == 1)
                blue++;
            else
                white++;

            return;
        }
        int mx = (fx + lx) / 2;
        int my = (fy + ly) / 2;

        partition(fx, fy, mx, my);
        partition(mx + 1, fy, lx, my);
        partition(fx, my + 1, mx, ly);
        partition(mx + 1, my + 1, lx, ly);
    }
}

int main()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    blue = 0;
    white = 0;

    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        for (size_t j = 1; j <= N; ++j)
            cin >> board[i][j];
    }

    partition(1, 1, N, N);

    cout << white << "\n"
         << blue;
    return 0;
}