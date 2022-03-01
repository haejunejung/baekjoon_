// 첫번쨰 시도에 비해서 메모리를 적게 사용하였다.. // 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define Max 1001

using namespace std;

int N, M, V;
bool check_dfs[Max], check_bfs[Max];
vector <int> vec[Max];

void DFS (int idx) {
    cout << idx << ' ';

    for (size_t s = 0; s < vec[idx].size(); ++s) {
        int next = vec[idx][s];
        if (!check_dfs[next]) {
            check_dfs[next] = true;
            DFS (next);
        }
    }
}

void BFS (int idx) {
    queue <int> q;
    q.push(idx);

    while (!q.empty()) {
        int idx = q.front();
        cout << idx << ' ';
        q.pop();

        for (size_t s = 0; s < vec[idx].size(); ++s) {
            int next = vec[idx][s];
            if (!check_bfs[next]) {
                check_bfs[next] = true;
                q.push(next);
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

        vec[a].push_back(b);
        vec[b].push_back(a);

        sort (vec[a].begin(), vec[a].end());
        sort (vec[b].begin(), vec[b].end());
        
    }
    check_dfs[V] = true;
    DFS (V);
    cout << '\n';

    check_bfs[V] = true;
    BFS (V);

    return 0;
}