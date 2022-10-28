#include <iostream>

#define MAX 300
int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int dp[2][MAX];
    for (int i = 0; i < T; ++i)
    {
        cin >> dp[0][i];
        dp[1][i] = dp[0][i];
    }

    for (int i = 1; i < T; ++i)
    {
        if (i == 1)
        {
            dp[1][i] = dp[1][i] + dp[0][i-1];
            continue;
        }
        dp[0][i] = dp[0][i] + max(dp[0][i-2], dp[1][i-2]);
        dp[1][i] = dp[1][i] + dp[0][i-1];
    }

    cout << max(dp[0][T-1], dp[1][T-1]);
    return 0;
}