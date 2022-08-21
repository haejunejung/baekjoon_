#include <iostream>

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    bool PrimeNum[1000001];
    fill_n(PrimeNum, 1000001, true);

    PrimeNum[0] = false;
    PrimeNum[1] = false;

    for (int i = 2; i*i <= 1000000; ++i)
    {
        if (PrimeNum[i])
        {
            for (int j = i + i; j <= 1000000; j+=i)
            {
                PrimeNum[j] = false;
            }
        }
    }

    for (testcase=1; testcase<=T; ++testcase)
    {
        int n;
        cin >> n;

        int count = 0;
        for (int i = 2; i*2<= n; ++i)
        {
            if (PrimeNum[i] && PrimeNum[n-i]) count++;
        }

        cout << count << "\n";
    }

    return 0;
}