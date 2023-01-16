#include <iostream>
#include <algorithm>

using namespace std;

void IO();

struct medal
{
    int idx = 0;
    int gold = 0;
    int silver = 0;
    int bronze = 0;
};

int main()
{
    IO();

    int N, K;
    cin >> N >> K;

    medal *country = new medal[N + 1];

    for (int i = 1; i <= N; ++i)
        cin >> country[i].idx >> country[i].gold >> country[i].silver >> country[i].bronze;

    sort(
        country + 1, country + N + 1, [](medal &a, medal &b)
        {
            if (a.gold == b.gold)
            {
                if (a.silver == b.silver)
                    return a.bronze > b.bronze;
                return a.silver > b.silver;
            }
            return a.gold > b.gold; });

    int count = 0;
    int coRank = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (((country[i - 1].gold == country[i].gold) && (country[i - 1].silver == country[i].silver) && (country[i - 1].bronze == country[i].bronze)))
        {
            coRank++;
        }
        else
        {
            count += coRank;
            coRank = 1;
        }

        if (country[i].idx == K)
            break;
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