#include <iostream>
#include <cstring>

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase)
    {
        int N, M, i, j;
        cin >> N;

        int coin[20] = { };
        int dp[10001];
        fill_n(dp, 10001, 0);
        for (i = 0; i < N; ++i)
        {
            cin >> coin[i];
        }

        cin >> M;

        for (i = 0; i < N; ++i)
        {
            for (j = coin[i]; j <= M; ++j)
            {
                if (j == coin[i]) 
                {
                    dp[j]++;
                    continue;
                }
                dp[j] = dp[j] + dp[j-coin[i]];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}