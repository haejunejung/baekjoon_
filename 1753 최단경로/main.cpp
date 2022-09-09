#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

int main (void)
{
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E,K;
    cin >> V >> E >> K;

    vector <pair<int,int>> graph[20001];
    int path[20001];
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i=1; i<=E; ++i)
    {
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back(make_pair(v,w));
    }

    for (int i=1; i<=V; ++i)
    {
        path[i] = INF;
    }
    path[K] = 0;

    pq.push(make_pair(0,K));

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int startPoint = pq.top().second;
        pq.pop();

        for (int i=0; i<graph[startPoint].size(); ++i)
        {
            int endPoint = graph[startPoint][i].first;
            int w = graph[startPoint][i].second;

            if (distance + w < path[endPoint])
            {
                path[endPoint] = distance + w;
                pq.push({distance+w, endPoint});
            }
        }
    }

    for (int i=1; i<=V; ++i)
    {
        if (path[i] == INF) cout << "INF\n";
        else cout << path[i] << "\n";
    }

    return 0;

}