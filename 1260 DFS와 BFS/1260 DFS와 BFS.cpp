// dfs (depth-first search)
// bfs (breath-first search)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define Max 1001

using namespace std;

int N, M, V;
bool map[Max][Max];
bool check_visited_dfs[Max], check_visited_bfs[Max];
queue <int> q;

void DFS (int idx) {
    cout << idx << ' ';

    for (int i = 1; i <= N; ++i) {
        if (map[idx][i] == true && check_visited_dfs[i] == false) {
            check_visited_dfs[i] = true;
            DFS (i);
        }
    }
}

void BFS (int idx) {
    q.push(idx);
    check_visited_bfs[idx] = true;

    while (!q.empty()) {
        idx = q.front();
        q.pop();

        cout << idx << ' ';

        for (int i = 1; i <= N; ++i) {
            if (map[idx][i] == true && check_visited_bfs[i] == false) {
                check_visited_bfs[i] = true;
                q.push(i);
            }
        }
    }
}


int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;

        map[a][b] = true;
        map[b][a] = true;
    }

    check_visited_dfs[V] = true;
    DFS (V);
    cout << '\n';

    BFS (V);

    return 0;

}