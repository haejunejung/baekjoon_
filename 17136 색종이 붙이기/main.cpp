#include <iostream>
#include <climits>

using namespace std;

int board[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int cnt, res;

void dfs (int y, int x)
{
    if (x == 10)
    {
        dfs (y+1, 0);
        return;
    }

    if (y == 10)
    {
        res = min(res, cnt);
        return;
    }

    if (board[y][x] == 0)
    {
        dfs (y, x+1);
        return;
    }

    for (int len = 5; len >= 1; len--)
    {
        if (paper[len] == 0 || y + len > 10 || x + len > 10)
        {
            continue;
        }

        bool flag = true;
        for (int j = 0; j < len; ++j)
        {
            for (int k = 0; k < len; ++k)
            {
                if (board[y+j][x+k] == 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag == false) break;
        }

        if (!flag) continue;

        for (int j = 0; j < len; ++j)
        {
            for (int k = 0; k < len; ++k)
            {
                board[y+j][x+k] = 0;
            }
        }

        paper[len]--;
        cnt++;

        dfs (y, x+len);

        for (int j = 0; j < len; ++j)
        {
            for (int k = 0; k < len; ++k)
            {
                board[y+j][x+k] = 1;
            }
        }

        paper[len]++;
        cnt--;
    }
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> board[i][j];
        }
    }

    res = INT_MAX;
    dfs (0,0);

    if (res == INT_MAX) cout << -1;
    else cout << res;
    return 0;



}