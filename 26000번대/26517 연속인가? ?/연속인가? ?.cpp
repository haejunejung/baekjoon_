// "Yes", "No" 라는 것에 주의하자 //
#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    long long k;
    cin >> k;

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a * k + b) == (c * k + d))
    {
        cout << "Yes " << (a * k + b);
    }
    else
        cout << "No";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}