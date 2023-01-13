/*
Using Binary Search (Two pointer)
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MIN_MAX -2000000000

using namespace std;

typedef long long ll;

vector<ll> liquid;

void solve(size_t l, size_t r)
{
    ll left = liquid[l];
    ll right = liquid[r];
    ll result = liquid[l] + liquid[r];

    while (l < r)
    {
        ll sum = liquid[l] + liquid[r];

        if (abs(sum) < abs(result))
        {
            result = sum;
            left = liquid[l];
            right = liquid[r];
        }

        if (sum <= 0)
            l++;
        else
            r--;
    }

    cout << left << " " << right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    for (size_t i = 0; i < N; ++i)
    {
        ll input;
        cin >> input;

        liquid.push_back(input);
    }

    sort(liquid.begin(), liquid.end(), [](ll &a, ll &b)
         { return a < b; });

    solve(0, N - 1);
    return 0;
}