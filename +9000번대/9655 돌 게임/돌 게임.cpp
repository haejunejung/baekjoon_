#include <iostream>

using namespace std;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool IsEvenIdx(int val)
{
    if (val % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    input();

    int N;
    cin >> N;

    bool flag = true;
    while (N > 0)
    {
        if ((N % 3) == 0)
        {
            if (IsEvenIdx(N / 3))
                N -= 3;
            else
                N -= 1;
        }
        else if ((N % 3) == 1)
        {
            if (IsEvenIdx(N / 3))
                N -= 1;
            else
                N -= 3;
        }
        else
        {
            if (IsEvenIdx(N / 3))
                N -= 1;
            else
                N -= 3;
        }

        if (N <= 0)
            break;

        flag = !flag;
    }

    if (flag)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}