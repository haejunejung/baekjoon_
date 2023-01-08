#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> v;

ll solve(ll left, ll right, ll M)
{
    ll maxLength = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2, total = 0;

        for (auto length : v)
        {
            if (length > mid)
                total += length - mid;
        }

        if (total >= M)
        {
            maxLength = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return maxLength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    for (size_t i = 0; i < N; ++i)
    {
        ll length;
        cin >> length;

        v.push_back(length);
    }

    cout << solve(0, *max_element(v.begin(), v.end()), M);

    return 0;
}