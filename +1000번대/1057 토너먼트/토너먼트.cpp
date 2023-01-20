#include <iostream>

using namespace std;

void IO();

int findNext(int val)
{
    if (val % 2 == 0)
        return val / 2;
    else
        return val / 2 + 1;
}

int main()
{
    IO();

    int N, jimin, hansu;
    cin >> N >> jimin >> hansu;

    int round = 1;
    bool flag = false;

    while (jimin > 0 && hansu > 0)
    {

        jimin = findNext(jimin);
        hansu = findNext(hansu);

        if (jimin == hansu)
        {
            flag = true;
            break;
        }

        round++;
    }

    if (flag)
        cout << round;
    else
        cout << -1;
    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}