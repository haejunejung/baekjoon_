#include <iostream>

int GCD (int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return GCD (y, x % y);
}

int main () 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase)
    {
        int n;
        cin >> n;

        int *input = new int[n];
        for (unsigned int i = 0; i < n; ++i)
        {
            cin >> input[i];
        }

        long long sum = 0;
        for (int i = 0; i < n-1; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                sum += GCD(input[i], input[j]);
            }
        }

        cout << sum << "\n";
    }
    return 0;
}