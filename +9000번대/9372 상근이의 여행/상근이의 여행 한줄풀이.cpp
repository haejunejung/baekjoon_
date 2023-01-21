#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
        }

        cout << N - 1 << "\n";
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}