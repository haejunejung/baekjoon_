#include <iostream>
#include <queue>
#include <vector>

#define none 0
#define black 1
#define white 2
#define Max 20001

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int V, E;
        cin >> V >> E;

        vector <int> graph[Max];
        queue <int> que;

        // 간선 연결 // 
        for (int j = 0; j < E; ++j) {
            int u,v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // bfs //
        int check_visited[Max] = {0};
        for (int k = 1; k <= V; ++k) {
            if (check_visited[k] == none) {
                check_visited[k] = black; // black or white , any color does not matter .. 
                que.push(k);

                while (!que.empty()) {
                    int idx = que.front();
                    que.pop();

                    for (size_t s = 0; s < graph[idx].size(); ++s) {
                        int next = graph[idx][s];

                        if (check_visited[next] == none) {
                            que.push(next);
                            if (check_visited[idx] == black) check_visited[next] = white;
                            else if (check_visited[idx] == white) check_visited[next] = black;
                        }
                    }
                }
            }
        }

        bool flag = true;
        for (int l = 1; l <= V; ++l) {
            for (size_t s = 0; s < graph[l].size(); ++s) {
                if (check_visited[l] == check_visited[graph[l][s]]) flag = false;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}