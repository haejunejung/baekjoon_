#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int A, B, N;
    cin >> A >> B >> N;

    A %= B;
    A *= 10;

    int n = 0, res = 0;
    while (n < N)
    {
        n++;
        res = (A / B);
        A %= B;
        A *= 10;
    }

    cout << res;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}