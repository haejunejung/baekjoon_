#include <iostream>

using namespace std;

void IO();

bool isSquare(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (i * i == n)
            return true;
    }

    return false;
}

int main()
{
    IO();

    int n;
    cin >> n;

    int *dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; ++i)
    {
        if (isSquare(i))
            dp[i] = 1;

        else
        {
            int minimum = 4;
            for (int j = 1; j * j <= i; ++j)
                minimum = min(minimum, dp[i - j * j]);
            dp[i] = minimum + 1;
        }
    }

    cout << dp[n];

    delete[] dp;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}