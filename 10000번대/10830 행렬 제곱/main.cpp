#include <iostream>
#include <vector>
#include <bitset>

#define mod 1000

using namespace std;

typedef long long ll;

ll N, B;

vector<vector<ll>> calMatrix(vector<vector<ll>> matrixA, vector<vector<ll>> matrixB)
{
    vector<vector<ll>> result(N, vector<ll>(N, 0));
    for (size_t n = 0; n < N; ++n)
    {
        for (size_t k = 0; k < N; ++k)
        {
            ll sum = 0;
            for (size_t m = 0; m < N; ++m)
            {
                sum += matrixA[n][m] * matrixB[m][k];
            }
            sum %= mod;
            result[n][k] = sum;
        }
    }

    return result;
}

void solve(vector<vector<ll>> matrixA)
{
    vector<vector<ll>> result;
    vector<vector<ll>> power = matrixA;

    bitset<38> b(B);

    for (size_t i = 0; i < b.size(); ++i)
    {
        if (b[i] == 1)
        {
            if (result.empty())
                result = power;
            else
                result = calMatrix(result, power);
        }
        power = calMatrix(power, power);
    }

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            cout << result[i][j] % mod << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> B;

    vector<vector<ll>> matrixA(N, vector<ll>(N, 0));
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            ll val;
            cin >> val;

            matrixA[i][j] = val;
        }
    }

    solve(matrixA);

    return 0;
}