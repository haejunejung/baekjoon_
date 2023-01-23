#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int index;
    int value;
};

void IO();

bool cmp(Node &a, Node &b)
{
    if (a.value == b.value)
    {
        return a.index < b.index;
    }

    return a.value < b.value;
}

int main()
{
    IO();

    vector<Node> v;
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int inp;
        cin >> inp;

        Node temp;
        temp.index = i;
        temp.value = inp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
    {
        P[v[i].index] = i;
    }

    for (auto val : P)
        cout << val << " ";

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// B[P[0]] = 2 (0, 2)
// B[P[1]] = 3 (1, 3)
// B[P[2]] = 1 (2, 1)

// (2, 1) (0, 2) (1, 3)
// P[2] = 0, P[0] = 1, P[1] = 2

// B[P[0]] = 2 2
// B[P[1]] = 1 0
// B[P[2]] = 3 3
// B[P[3]] = 1 1
