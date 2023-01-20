#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int K, A = 1, B = 0;
    cin >> K;

    for (int i = 1; i <= K; ++i)
    {
        int a = A;
        int b = B;

        B += a;
        A -= a;
        A += b;
    }

    cout << A << " " << B;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}