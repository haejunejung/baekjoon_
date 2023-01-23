#include <iostream>

using namespace std;

char star[500][500];

void IO();

void solve(int N, int start)
{
    if (N < 1)
        return;

    for (int i = start; i < start + N; ++i)
    {
        for (int j = start; j < start + N; ++j)
        {
            if (i == start || i == start + N - 1 || j == start || j == start + N - 1)
                star[i][j] = '*';
        }
    }

    solve(N - 4, start + 2);
}

int main()
{
    IO();

    int N;
    cin >> N;

    for (int i = 0; i < 4 * N - 3; ++i)
    {
        for (int j = 0; j < 4 * N - 3; ++j)
            star[i][j] = ' ';
    }

    solve(4 * N - 3, 0);

    for (int i = 0; i < 4 * N - 3; ++i)
    {
        for (int j = 0; j < 4 * N - 3; ++j)
            cout << star[i][j];
        cout << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}