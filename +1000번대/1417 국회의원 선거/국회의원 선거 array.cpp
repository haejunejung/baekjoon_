#include <iostream>
#include <algorithm>

using namespace std;

void IO();

int main()
{
    IO();

    int candidate[50];
    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> candidate[i];

    while (N > 1 && candidate[0] <= *max_element(candidate + 1, candidate + N))
    {
        int maxIdx = max_element(candidate + 1, candidate + N) - candidate;
        candidate[maxIdx]--;
        count++;
        candidate[0]++;
    }

    cout << count;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}