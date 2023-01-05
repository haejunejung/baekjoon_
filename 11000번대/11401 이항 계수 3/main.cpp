#include <iostream>
#include <bitset>
using namespace std;

#define mod 1000000007

typedef long long ll;

ll N, K;

bool isPrime(ll val)
{
    for (size_t i = 2; i * i <= val; ++i)
    {
        if (val % i == 0)
            return false;
    }
    return true;
}

ll modularExp(ll val)
{
    bitset<32> b(mod - 2);
    ll result = 1;
    ll power = val % mod;

    for (size_t i = 0; i <= 31; ++i)
    {
        if (b[i] == 1)
        {
            result = (result * power) % mod;
        }
        power = (power * power) % mod;
    }

    return result;
}

ll modularMul(ll start, ll end)
{
    ll result = 1;
    for (ll val = start; val <= end; ++val)
    {
        result = (result * val) % mod;
    }

    return result;
}

void solve()
{
    ll Denom = modularMul(N - K + 1, N);
    ll nom = modularMul(2, K);

    cout << ((Denom % mod) * (modularExp(nom) % mod)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    solve();

    return 0;
}