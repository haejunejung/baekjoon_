// 계속 연결되어 있는 걸 중점으로 생각..
// dfs를 이용하여 풀이

#include <iostream>

#define MAX 1001

using namespace std;

int N, M, ans;
bool map[MAX][MAX];
bool check_visited[MAX];

void dfs (int idx) {
    check_visited[idx] = true;

    for (int i = 1; i <= N; ++i) {
        if (map[idx][i] && !check_visited[i]) {
            dfs(i);
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;

        map[a][b] = true;
        map[b][a] = true;
    }

    for (int i = 1; i <= N; ++i) {
        if (!check_visited[i]) {
            ++ans;
            dfs (i);
        }
    }

    cout << ans;
    return 0;
}