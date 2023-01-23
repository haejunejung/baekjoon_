#include <iostream>
#include <algorithm>

using namespace std;

void IO();

int main()
{
    IO();

    int N, M;
    cin >> N >> M;

    int *armor = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> armor[i];
    sort(armor, armor + N);

    int l = 0, r = N - 1, count = 0;
    while (l < r)
    {
        int left = armor[l], right = armor[r];
        if (left + right < M)
            l++;
        else if (left + right > M)
            r--;
        else
        {
            l++;
            r--;
            count++;
        }
    }

    cout << count;

    delete[] armor;

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}