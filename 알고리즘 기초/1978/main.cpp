#include <iostream>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    bool PrimeNum[1001] = { };
    fill_n(PrimeNum, 1001, true);

    PrimeNum[0] = false;
    PrimeNum[1] = false;

    for (int i = 2; i < 1001; ++i)
    {
        if (PrimeNum[i])
        {
            for (int j = i + i; j < 1001; j += i)
                PrimeNum[j] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;

        if (PrimeNum[n]) count++;
    }

    cout << count << '\n';

    return 0;
}