#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

typedef vector<int> vec;

vec graph[MAX];
queue<int> res;
int order[MAX];
bool check[MAX];

void dfs(int x)
{
    if (check[x])
        return;

    if (res.front() != x)
    {
        cout << 0;
        exit(0);
    }

    res.pop();
    check[x] = true;

    for (auto point : graph[x])
    {
        if (!check[point])
            dfs(point);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    for (size_t i = 0; i < N - 1; ++i)
    {
        int p1, p2;
        cin >> p1 >> p2;

        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }

    for (size_t i = 1; i <= N; ++i)
    {
        int p;
        cin >> p;

        res.push(p);
        order[p] = i;
    }

    for (size_t i = 1; i <= N; ++i)
        sort(graph[i].begin(), graph[i].end(), [](int a, int b)
             { return order[a] < order[b]; });

    dfs(1);

    cout << 1;

    return 0;
}