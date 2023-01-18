#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void IO();

int main()
{
    IO();

    vector<int> v;
    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int value;
        cin >> value;

        v.push_back(value);
    }

    while (v.size() > 1 && v[0] <= *max_element(v.begin() + 1, v.end()))
    {
        int maxIdx = max_element(v.begin() + 1, v.end()) - v.begin();
        v[maxIdx]--;
        count++;
        v[0]++;
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