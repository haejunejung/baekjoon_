#include <iostream>

using namespace std;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    input();

    int N;
    cin >> N;

    unsigned int count = 1, l = 1, r = 1;
    long long sum = 0;

    while (l <= r && l <= (N / 2) && r <= N)
    {
        if (sum < N)
            sum += r++;
        else
        {
            if (sum == N)
                count++;
            sum -= l++;
        }
    }

    cout << count;

    return 0;
}