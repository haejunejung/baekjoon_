#include <iostream>

typedef long long ll;

int n, m, k;
ll Bboard[2001][2001];
ll Wboard[2001][2001];

int main()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    ll ans = 2001 * 2001;

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= m; ++j)
        {
            char color;
            cin >> color;

            if (((i + j) % 2 == 0 && color == 'W') || ((i + j) % 2 == 1 && color == 'B'))
            {
                Bboard[i][j] = Bboard[i - 1][j] + Bboard[i][j - 1] - Bboard[i - 1][j - 1];
                Wboard[i][j] = Wboard[i - 1][j] + Wboard[i][j - 1] - Wboard[i - 1][j - 1] + 1;
            }
            else
            {
                Bboard[i][j] = Bboard[i - 1][j] + Bboard[i][j - 1] - Bboard[i - 1][j - 1] + 1;
                Wboard[i][j] = Wboard[i - 1][j] + Wboard[i][j - 1] - Wboard[i - 1][j - 1];
            }
        }
    }

    for (size_t i = 1; i <= n - k + 1; ++i)
    {
        for (size_t j = 1; j <= m - k + 1; ++j)
        {
            ll W_pSum = Wboard[i + k - 1][j + k - 1] - Wboard[i + k - 1][j - 1] - Wboard[i - 1][j + k - 1] + Wboard[i - 1][j - 1];
            ll B_pSum = Bboard[i + k - 1][j + k - 1] - Bboard[i + k - 1][j - 1] - Bboard[i - 1][j + k - 1] + Bboard[i - 1][j - 1];
            ans = min(ans, min(W_pSum, B_pSum));
        }
    }

    cout << ans;

    return 0;
}