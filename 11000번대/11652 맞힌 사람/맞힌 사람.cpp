#include <iostream>
#include <map>

using namespace std;

typedef signed long long sll;

struct Node
{
    sll value;
    size_t count;
};

void IO();

int main()
{
    IO();

    int N;
    cin >> N;

    map<sll, size_t> m;

    for (int i = 0; i < N; ++i)
    {
        sll card;
        cin >> card;

        m[card] += 1;
    }

    sll result;
    size_t maximum = 0;
    for (auto val : m)
    {
        if (maximum < val.second)
        {
            result = val.first;
            maximum = val.second;
        }
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