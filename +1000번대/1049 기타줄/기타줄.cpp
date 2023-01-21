#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M;
    cin >> N >> M;

    int minSix = 6000, minOne = 1000, minPrice = 0;

    while (M--)
    {
        int sixPrice, onePrcie;
        cin >> sixPrice >> onePrcie;

        minSix = min(minSix, sixPrice);
        minOne = min(minOne, onePrcie);
    }

    while (N)
    {
        if (N >= 6)
        {
            if (minSix > minOne * 6)
            {
                minPrice += minOne * N;
                N = 0;
            }
            else
            {
                minPrice += minSix * (N / 6);
                N %= 6;
            }
        }
        else
        {
            if (minSix > minOne * N)
            {
                minPrice += minOne * N;
                N = 0;
            }
            else
            {
                minPrice += minSix;
                N = 0;
            }
        }
    }

    cout << minPrice;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}