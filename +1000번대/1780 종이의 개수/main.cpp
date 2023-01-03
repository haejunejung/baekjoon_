#include <iostream>
#include <vector>

#define MAX 2188
using namespace std;

int board[MAX][MAX];
int OnlyMinusOne, OnlyZero, OnlyOne;

void paperCount(int paper)
{
    switch (paper)
    {
    case -1:
        OnlyMinusOne++;
        break;
    case 0:
        OnlyZero++;
        break;
    case 1:
        OnlyOne++;
        break;

    default:
        break;
    }
}

bool check(int x, int y, int len)
{
    int n = board[y][x];
    for (int i = y; i < y + len; ++i)
    {
        for (int j = x; j < x + len; ++j)
        {
            if (board[i][j] != n)
                return false;
        }
    }
    return true;
}

void partition(int x, int y, int len)
{
    if (check(x, y, len))
    {
        paperCount(board[y][x]);
        return;
    }

    int newlen = len / 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            partition(x + newlen * j, y + newlen * i, newlen);
        }
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
        for (size_t j = 1; j <= N; ++j)
            cin >> board[i][j];
    }

    OnlyMinusOne = 0;
    OnlyZero = 0;
    OnlyOne = 0;

    partition(1, 1, N);

    cout << OnlyMinusOne << "\n"
         << OnlyZero << "\n"
         << OnlyOne;

    return 0;
}