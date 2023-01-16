#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int X;
    cin >> X;

    int max2exp = 1;
    while (max2exp <= X)
    {
        max2exp *= 2;
    }

    max2exp /= 2;

    int count = 0;
    int sum = 0;

    while (sum != X)
    {
        sum += max2exp;
        if (sum > X)
        {
            sum -= max2exp;
            count--;
        }
        count++;
        max2exp /= 2;
    }

    cout << count;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}