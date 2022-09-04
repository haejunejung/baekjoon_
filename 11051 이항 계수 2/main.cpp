#include <iostream>

#define MAX 1001
int dp[MAX][MAX];

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; ++i)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K];
    return 0;
}