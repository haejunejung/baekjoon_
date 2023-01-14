#include <iostream>
#include <algorithm>

using namespace std;

const unsigned int MAX = 5000000;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long A[MAX];

int main()
{
    input();

    int N, k;
    cin >> N >> k;

    for (size_t i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sort(A, A + N, [](long long &a, long long &b)
         { return a < b; });

    cout << A[k - 1];

    return 0;
}