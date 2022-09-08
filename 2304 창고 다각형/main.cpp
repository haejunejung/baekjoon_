#include <iostream>
#include <algorithm>
#include <utility>

bool compare (std::pair<int,int> &a, std::pair<int,int> &b)
{
    return a.first < b.first;
}

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    std::pair <int, int> *pillar = new std::pair <int, int> [N];
    for (int i = 0; i < N; ++i)
    {
        int L,H;
        cin >> L >> H;
        pillar[i] = {L,H};
    }

    sort (pillar, pillar+N, compare);

    int sum = 0;
    int L = pillar[0].first;
    int H = pillar[0].second;
    for (int i = 1; i < N; ++i)
    {
        if (H <= pillar[i].second)
        {
            sum += (pillar[i].first - L) * H;
            L = pillar[i].first;
            H = pillar[i].second;
        }
    }

    sum += H;
    L = pillar[N-1].first;
    H = pillar[N-1].second;

    for (int i = N-2; i >=0; --i)
    {
        if (H < pillar[i].second)
        {
            sum += (L - pillar[i].first) * H;
            L = pillar[i].first;
            H = pillar[i].second;
        }
    }

    cout << sum << "\n";
    return 0;
}