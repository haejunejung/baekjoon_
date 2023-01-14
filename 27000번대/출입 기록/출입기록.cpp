#include <iostream>

using namespace std;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    int N, count = 0;
    cin >> N;

    int num[200001] = {};

    while (N--)
    {
        int a, b;
        cin >> a >> b;

        if (num[a] == b)
            count++;
        else
            num[a] = b;
    }

    for (int i = 1; i <= 200000; ++i)
    {
        if (num[i])
            count++;
    }

    cout << count;

    return 0;
}