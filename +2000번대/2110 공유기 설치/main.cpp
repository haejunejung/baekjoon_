#include <iostream>
#include <algorithm>

#define MAX 200000

using namespace std;

typedef long long ll;

ll x[MAX];
ll N, C;

bool istrue(ll diff)
{
    ll start = x[0];
    ll count = 1;

    for (size_t i = 1; i < N; ++i)
    {
        if (x[i] - start >= diff)
        {
            start = x[i];
            count++;
        }
    }

    if (count >= C)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> C;

    for (size_t i = 0; i < N; ++i)
    {
        cin >> x[i];
    }

    sort(x, x + N, [](ll &a, ll &b)
         { return a < b; });

    ll start = 1;
    ll end = x[N - 1];
    ll maximum = 0;

    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (istrue(mid))
        {
            maximum = max(maximum, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << maximum;

    return 0;
}