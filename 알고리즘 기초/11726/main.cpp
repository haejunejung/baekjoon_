#include <iostream>

#define type unsigned long long

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    type method[1001] = { }; /* bottom - up method */
    method[1] = 1;
    method[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        method[i] = (method[i-2] + method[i-1]) % 10007; /* memorization */
    }

    cout << method[n];
    return 0;

}