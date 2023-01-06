#include <iostream>
#include <vector>
#include <bitset>

#define mod 1000000007

using namespace std;

typedef unsigned long long ull;

vector<vector<ull>> calMatrix(vector<vector<ull>> matrixA, vector<vector<ull>> matrixB)
{
    vector<vector<ull>> result(2, vector<ull>(2, 0));
    for (size_t n = 0; n < 2; ++n)
    {
        for (size_t k = 0; k < 2; ++k)
        {
            ull sum = 0;
            for (size_t m = 0; m < 2; ++m)
            {
                sum += matrixA[n][m] * matrixB[m][k];
                sum %= mod;
            }
            result[n][k] = sum;
        }
    }
    return result;
}

void fibo(ull n)
{
    bitset<64> b(n);

    vector<vector<ull>> result;
    vector<vector<ull>> power(2, vector<ull>(2, 1));
    power[1][1] = 0;

    for (size_t i = 0; i < 64; ++i)
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

    cout << result[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull n;
    cin >> n;

    fibo(n);

    return 0;
}

/*
#include <iostream>
#include <vector>

#define mod 1000000007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator*(matrix &matrixA, matrix &matrixB)
{
    matrix matrixC(2, vector<ll>(2));

    for (size_t i = 0; i < 2; ++i)
    {
        for (size_t j = 0; j < 2; ++j)
        {
            ll sum = 0;
            for (size_t k = 0; k < 2; ++k)
            {
                sum += matrixA[i][k] * matrixB[k][j];
                sum %= mod;
            }
            matrixC[i][j] = sum;
        }
    }

    return matrixC;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    matrix result = {{1, 0}, {0, 1}};
    matrix power = {{1, 1}, {1, 0}};

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = result * power;
        }
        power = power * power;
        n /= 2;
    }

    cout << result[0][0] << " " << result[0][1] << endl;
    return 0;
}
*/