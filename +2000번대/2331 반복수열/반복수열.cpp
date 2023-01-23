#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void IO();

ll pSum(ll n, int P)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += pow(n % 10, P);
        n /= 10;
    }

    return sum;
}

int main()
{
    IO();

    int A, P;
    cin >> A >> P;

    vector<ll> v;
    v.push_back(A);

    int iterStart = 0;

    while (true)
    {
        bool flag = false;
        for (int i = 0; i < int(v.size()) - 1; ++i)
        {
            if (v[i] == v.back())
            {
                iterStart = i;
                flag = true;
                break;
            }
        }

        if (flag)
            break;

        ll temp = pSum(A, P);
        v.push_back(temp);
        A = temp;
    }

    cout << iterStart;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}