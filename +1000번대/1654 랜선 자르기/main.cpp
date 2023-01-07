#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;

vec LAN;

ll findMax(ll want, ll start, ll end)
{
    ll maximum = 0;
    while (start <= end)
    {
        ll mid = (start + end) / 2;

        ll count = 0;
        for (auto val : LAN)
        {
            count += val / mid;
        }

        if (count >= want)
        {
            start = mid + 1;
            maximum = mid;
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

    ll K, N;
    cin >> K >> N;

    for (size_t i = 0; i < K; ++i)
    {
        ll val;
        cin >> val;

        LAN.push_back(val);
    }

    sort(LAN.begin(), LAN.end(), [](ll &a, ll &b)
         { return a < b; });

    cout << findMax(N, 1, LAN[K - 1]);

    return 0;
}