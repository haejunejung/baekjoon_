#include <iostream>
#include <vector>

#define none 0
#define black 1
#define white 2
#define Max 20001

using namespace std;

void dfs (int start, vector <int> graph[], int check_visited[]) {
    for (size_t s = 0; s < graph[start].size(); ++s) {
        int next = graph[start][s];
        if (check_visited[next] == none) {
            if (check_visited[start] == black) check_visited[next] = white;
            else if (check_visited[start] == white) check_visited[next] = black;
            dfs (next, graph, check_visited);
        }
    }

    return;
}

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
        for (int j = 0; j < E; ++j) {
            int u,v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int check_visited[Max] = {none};
        for (int j = 1; j <= V; ++j) {
            if (check_visited[j] == none) {
                check_visited[j] = black;
                dfs (j, graph, check_visited);
            }
        }

        bool flag = true;
        for (int j = 1; j <= V; ++j) {
            for (size_t s = 0; s < graph[j].size(); ++s) {
                if (check_visited[j] == check_visited[graph[j][s]]) flag = false;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}