// BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void IO();

void bfs(int N, int M, vector<int> graph[])
{
    int result = 10000, airplaneType = 0;
    queue<int> q;          // bfs를 위한 queue
    bool check[1001] = {}; // country check
    q.push(1);
    check[1] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto val : graph[f])
        {
            if (!check[val])
            {
                check[val] = true;
                q.push(val);
                airplaneType++;
            }
        }
    }

    result = min(result, airplaneType);

    cout << result << '\n';
}

int main()
{
    IO();

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> graph[1001];
        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bfs(N, M, graph);
    }

    return 0;
}

void IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}