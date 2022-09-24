/* O(n^2) 으로 시간초과 -> O(nlongn)의 방법 찾아보기 */
#include <iostream>

int main (void) 
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long *input = new long long[N];
    long long *dp = new long long[N];
    long long *length = new long long[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> input[i];
        dp[i] = i;
        length[i] = 1;
    }

    int maxlen = 1, maxdp = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (input[j] < input[i])
            {
                if (length[i] < length[j]+1)
                {
                    length[i] = length[j]+1;
                    dp[i] = j;

                    if (maxlen < length[i])
                    {
                        maxlen = length[i];
                        maxdp = i;
                    }
                }  
            }
        }
    }

    cout << maxlen << "\n";
    long long *res = new long long[maxlen];

    for (int i = 0; i < maxlen; ++i)
    {
        res[i] = input[maxdp];
        maxdp = dp[maxdp];
    }

    for (int i = maxlen-1; i >=0; --i)
    {
        cout << res[i] << " ";
    }

    return 0;
}