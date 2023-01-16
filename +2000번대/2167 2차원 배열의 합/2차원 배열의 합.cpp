#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M;
    cin >> N >> M;

    int board[301][301];
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    }

    int K;
    cin >> K;

    while (K--)
    {
        int i, j, x, y, sum = 0;
        cin >> i >> j >> x >> y;

        for (int a = i; a <= x; ++a)
        {
            for (int b = j; b <= y; ++b)
                sum += board[a][b];
        }

        cout << sum << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}