#include <iostream>
#include <algorithm>

using namespace std;

typedef signed long long sll;

void IO();

int main()
{
    IO();

    int N;
    cin >> N;

    sll card[100000], result;

    for (int i = 0; i < N; ++i)
        cin >> card[i];

    sort(card, card + N, [](sll &a, sll &b)
         { return a < b; });

    int maxCount = 0;
    for (int i = 0; i < N;)
    {
        int j = i, count = 0;
        while (j < N && card[j] == card[i])
        {
            j++;
            count++;
        }

        if (maxCount < count)
        {
            maxCount = count;
            result = card[i];
        }

        i = j;
    }

    cout << result;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}