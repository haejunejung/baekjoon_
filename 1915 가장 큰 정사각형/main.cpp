#include <iostream>
#include <cstring>

int dp[1000][1000];

int main (void) 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;

        for (size_t j = 0; j < input.length(); ++j)
        {
            dp[i][j] = input[j] - '0';
        }
    }

    int length = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j] != 0)
            {
                if (i > 0 && j > 0)
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }

                if (length < dp[i][j]) length = dp[i][j];
            }
        }
    }

    cout << length * length << endl;
    return 0;
}