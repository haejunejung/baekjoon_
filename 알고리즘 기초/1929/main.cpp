#include <iostream>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    bool *PrimeNum = new bool[N+1];
    fill_n(PrimeNum, N+1, true);
    PrimeNum[0] = false;
    PrimeNum[1] = false;

    for (int i = 2; i < N+1; ++i)
    {
        if (PrimeNum[i])
        {
            for (int j = i + i; j < N+1; j += i)
                PrimeNum[j] = false;
        }
    }

    for (int i = M; i <= N; ++i)
    {
        if (PrimeNum[i]) cout << i << '\n';
    }
    
    return 0;
}