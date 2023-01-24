#include <iostream>
#include <algorithm>

using namespace std;

void IO();

int main()
{
    IO();

    int N, L;
    cin >> N >> L;

    int leakPoint[1000];
    for (int i = 0; i < N; ++i)
        cin >> leakPoint[i];

    sort(leakPoint, leakPoint + N, [](int &a, int &b)
         { return a < b; });

    int tape = 1, start = leakPoint[0];
    for (int i = 1; i < N; ++i)
    {
        if (leakPoint[i] - start >= L)
        {
            tape++;
            start = leakPoint[i];
        }
    }

    cout << tape;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}