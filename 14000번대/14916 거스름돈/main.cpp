#include <iostream>

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int share = n / 5;
    int remainder = n % 5;

    while (remainder % 2 != 0)
    {
        share -= 1;
        remainder += 5;
    }

    if (share < 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << share + (remainder / 2);
    }

    return 0;
}