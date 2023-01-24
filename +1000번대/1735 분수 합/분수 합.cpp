#include <iostream>

using namespace std;

void IO();

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int denom(int b, int d)
{
    return lcm(b, d);
}

int numer(int a, int b, int c, int d)
{
    return ((a * d + b * c) / gcd(b, d));
}

int main()
{
    IO();

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int DENOM = denom(b, d);
    int NUMER = numer(a, b, c, d);
    int GCD = gcd(NUMER, DENOM);

    cout << NUMER / GCD << " " << DENOM / GCD;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}