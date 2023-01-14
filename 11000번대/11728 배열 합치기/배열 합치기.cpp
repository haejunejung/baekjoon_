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

    int N, M;
    cin >> N >> M;

    const unsigned int MAX = 1000000;

    int A[MAX], B[MAX];

    for (size_t i = 0; i < N; ++i)
        cin >> A[i];

    for (size_t j = 0; j < M; ++j)
        cin >> B[j];

    int an = 0, bm = 0;
    while (an < N && bm < M)
    {
        if (A[an] < B[bm])
        {
            cout << A[an] << " ";
            an++;
        }
        else
        {
            cout << B[bm] << " ";
            bm++;
        }
    }

    while (an < N)
    {
        cout << A[an] << " ";
        an++;
    }

    while (bm < M)
    {
        cout << B[bm] << " ";
        bm++;
    }

    return 0;
}