#include <iostream>

int price[101], dp[10001];

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> price[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = price[i]; j <= k; ++j)
        {
            dp[j] = dp[j] + dp[j-price[i]];
        }
    }

    cout << dp[k];
    return 0;
}