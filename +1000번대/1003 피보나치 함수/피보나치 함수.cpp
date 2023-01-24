#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase)
    {
        int N;
        cin >> N;

        int fibo[41][2] = {};
        fibo[0][0] = 1;
        fibo[1][1] = 1;

        for (int i = 2; i <= N; ++i)
        {
            fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
            fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
        }

        cout << fibo[N][0] << " " << fibo[N][1] << "\n";
    }
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}