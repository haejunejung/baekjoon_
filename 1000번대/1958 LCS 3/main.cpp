#include <iostream>
#include <cstring>

int dp[101][101][101];

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    for (size_t i = 1; i <= str3.length(); ++i)
    {
        for (size_t j = 1; j <= str2.length(); ++j)
        {
            for (size_t k = 1; k <= str1.length(); ++k)
            {
                if (str1[k-1] == str2[j-1] && str2[j-1] == str3[i-1])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }

    cout << dp[str3.length()][str2.length()][str1.length()];
    
    return 0;
}
