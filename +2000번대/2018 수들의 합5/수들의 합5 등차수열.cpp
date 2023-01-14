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

    unsigned int count = 0;
    for (int k = 1;; ++k)
    {
        unsigned int oneToK = (k * (k + 1)) / 2;
        if (oneToK > N)
            break;
        if ((N - oneToK) % k == 0)
            count++;
    }

    cout << count;

    return 0;
}