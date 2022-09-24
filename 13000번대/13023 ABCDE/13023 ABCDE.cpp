#include <iostream>
#include <vector>

#define Max 2001

using namespace std;

int N, M;
bool flag, check[Max];
vector <int> vec[Max];

void dfs (int cnt, int pos) {
    if (cnt == 4) {
        flag = true;
        return;
    }

    check[pos] = true;

    for (int i = 0; i < vec[pos].size(); ++i) {
        int next = vec[pos][i];
        if (check[next] == false) dfs (cnt+1, next);
    }

    check[pos] = false;
    return;

}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;

        vec[start].push_back(end);
        vec[end].push_back(start);
    }

    for (int i = 0; i < N; ++i) {
        dfs (0, i);
        if (flag == true) break; // 시간 단축
    }

    if (flag == true) cout << 1;
    else cout << 0;

    return 0;
}