#include <iostream>

using namespace std;

const unsigned int MAX = 2001;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    int N;
    cin >> N;

    bool arr[MAX] = {};
    for (int i = 0; i < N; ++i)
    {
        int inp;
        cin >> inp;

        arr[inp + 1000] = true;
    }

    for (int i = 0; i < MAX; ++i)
    {
        if (arr[i])
            cout << i - 1000 << " ";
    }

    return 0;
}