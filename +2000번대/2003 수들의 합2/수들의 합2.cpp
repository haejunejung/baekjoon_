#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M, result = 0;
    cin >> N >> M;

    long long A[10001] = {};
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (A[i] - A[j] == M)
            {
                result++;
                break;
            }
        }
    }

    cout << result;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}