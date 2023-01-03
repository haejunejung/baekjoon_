#include <iostream>
#include <bitset>
using namespace std;

typedef long long ll;

ll a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;

    bitset<32> binary(b);

    ll result = 1;
    ll power = a % c;

    for (int i = 0; i < binary.size(); ++i)
    {
        if (binary[i] == 1)
        {
            result = (result * power) % c;
        }
        power = (power * power) % c;
    }

    cout << result;

    return 0;
}