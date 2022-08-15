#include <iostream>

long long count (long long n, long long x)
{
    long long ans = 0;
    for (long long i = x; i <= n; i *= x)
    {
        ans += n / i;
    }

    return ans;
}

int main ()
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,m;
    cin >> n >> m;

    long long countTwo = count(n,2) - count(n-m,2) - count(m,2);
    long long countFive = count(n,5) - count(n-m,5) - count(m,5);
    
    cout << std::min(countTwo, countFive);

    return 0;
}