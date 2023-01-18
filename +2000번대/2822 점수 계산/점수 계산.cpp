#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int order;
    int value;
};

void IO();

int main()
{
    IO();

    vector<Node> v;
    for (int i = 1; i <= 8; ++i)
    {
        int score;
        cin >> score;

        Node x;
        x.order = i;
        x.value = score;

        v.push_back(x);
    }

    sort(v.begin(), v.end(), [](Node &a, Node &b)
         { return a.value > b.value; });

    for (int i = 0; i < 3; ++i)
        v.pop_back();

    sort(v.begin(), v.end(), [](Node &a, Node &b)
         { return a.order < b.order; });

    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += v[i].value;

    cout << sum << "\n";

    for (int i = 0; i < 5; ++i)
        cout << v[i].order << " ";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}