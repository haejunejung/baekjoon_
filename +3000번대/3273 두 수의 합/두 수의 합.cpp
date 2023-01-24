#include <iostream>
#include <algorithm>

using namespace std;

void IO();

int main()
{
    IO();

    int n, x, l, r, count = 0;
    cin >> n;

    int *sequence = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> sequence[i];
    cin >> x;

    sort(sequence, sequence + n, [](int &a, int &b)
         { return a < b; });

    l = 0;
    r = n - 1;
    while (l < r)
    {
        int sum = sequence[l] + sequence[r];
        if (sum < x)
            l++;
        else if (sum > x)
            r--;
        else
        {
            count++;
            l++;
            r--;
        }
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