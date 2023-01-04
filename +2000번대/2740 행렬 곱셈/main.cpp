#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;

    int A[100][100];
    int B[100][100];

    cin >> N >> M;

    for (int n = 0; n < N; ++n)
    {
        for (int m = 0; m < M; ++m)
            cin >> A[n][j];
    }

    cin >> M >> K;

    for (int m = 0; m < M; ++m)
    {
        for (int k = 0; k < K; ++k)
            cin >> B[m][k];
    }

    for (int n = 0; n < N; ++n)
    {
        for (int k = 0; k < K; ++k)
        {
            int sum = 0;
            for (int m = 0; m < M; ++m)
            {
                sum += A[n][m] * B[m][k];
            }
            cout << sum << " ";
        }
        cout << "\n";
    }

    return 0;
}