#include <iostream>

using namespace std;

void IO();

int main()
{
    IO();

    int N, K, count = 0, result = 0;
    cin >> N >> K;

    bool number[1001];
    fill_n(number, 1001, true);
    for (int i = 2; i <= N; ++i)
    {
        if (number[i])
        {
            for (int j = i; j <= N; j += i)
            {
                if (number[j])
                {
                    number[j] = false;
                    count++;
                }

                if (count == K)
                {
                    cout << j;
                    return 0;
                }
            }
        }
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}