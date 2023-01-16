#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int X, count = 0;
    cin >> X;

    for (int bit = 1; bit <= 64; bit <<= 1)
        if (bit & X)
            count++;

    cout << count;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}