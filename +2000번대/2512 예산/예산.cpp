#include <iostream>

#define MAX 10000

using namespace std;

typedef long long ll;

ll province[MAX];

ll solve(ll start, ll end, ll N, ll M)
{
    ll maximum = 0;
    while (start <= end)
    {
        ll mid = (start + end) / 2, sum = 0;

        for (size_t i = 0; i < N; ++i)
        {
            if (province[i] - mid > 0)
                sum += mid;
            else
                sum += province[i];
        }

        if (sum <= M)
        {
            maximum = max(maximum, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M, maximum = 0;
    cin >> N;

    for (size_t i = 0; i < N; ++i)
    {
        cin >> province[i];
        maximum = max(maximum, province[i]);
    }

    cin >> M;

    cout << solve(1, maximum, N, M);

    return 0;
}