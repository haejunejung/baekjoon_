#include <iostream>
#include <cstring>

using namespace std;

void IO();

string addTwoStrings(string a, string b)
{
    string result;
    int sum = 0;
    int len = max(a.size(), b.size());

    for (int i = 0; i < len || sum; ++i)
    {
        if (a.size() > i)
            sum += a[i] - '0';
        if (b.size() > i)
            sum += b[i] - '0';

        result += (sum % 10) + '0';
        sum /= 10;
    }

    return result;
}

int main()
{
    IO();

    int n, m;
    cin >> n >> m;

    string combination[101][101];
    combination[1][0] = '1';
    combination[1][1] = '1';

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
                combination[i][j] = '1';

            else
                combination[i][j] = addTwoStrings(combination[i - 1][j], combination[i - 1][j - 1]);
        }
    }

    for (int i = combination[n][m].size() - 1; i >= 0; --i)
    {
        cout << combination[n][m][i];
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}