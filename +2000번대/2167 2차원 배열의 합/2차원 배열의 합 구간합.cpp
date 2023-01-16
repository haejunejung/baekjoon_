#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M, K;
    cin >> N >> M;

    int matrix[301][301] = {};
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> matrix[i][j];
            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
        }
    }

    cin >> K;
    while (K--)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        cout << matrix[x][y] - matrix[i - 1][y] - matrix[x][j - 1] + matrix[i - 1][j - 1] << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}