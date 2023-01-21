#include <iostream>
#include <cstring>
#include <map>

using namespace std;

void IO();

int main()
{
    IO();

    map<string, size_t> m;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string title;
        cin >> title;

        if (m.find(title) == m.end())
            m.insert(make_pair(title, 1));
        else
            m[title] += 1;
    }

    string result;
    size_t maximum = 0;

    for (auto value : m)
    {
        if (value.second > maximum)
        {
            result = value.first;
            maximum = value.second;
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