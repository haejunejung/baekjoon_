// 계속 연결되어 있는 걸 중점으로 생각..
// dfs를 이용하여 풀이

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int N, M;
bool check_visited[MAX];
vector <int> vec[MAX];

void dfs (int idx) {
    check_visited[idx] = true;
    for (size_t s = 0; s < vec[idx].size(); ++s) {
        int next = vec[idx][s];
        if (!check_visited[next]) {
            dfs (next);
        }
    }

    return;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int ans = 0;

    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);

    }

    for (int i = 1; i <= N; ++i) {
        // if (!check_visited[i] && !vec[i].empty()) 의 경우는 틀렸다. 
        // 이유를 모르겠다 .. 
        if (!check_visited[i]) {
            ++ans;
            dfs (i);
        }
    }

    cout << ans;
    return 0;
}