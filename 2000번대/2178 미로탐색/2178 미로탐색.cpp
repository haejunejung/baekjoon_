#include <iostream>
#include <string>
#include <queue>

#define Max 100

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 필요 정보 // 
    int N, M, map[Max][Max] = {0}, length[Max][Max] = {1};
    bool check_visited[Max][Max] = {false};
    queue < pair<int,int> > que;
    int da[4] = {-1,1,0,0};
    int db[4] = {0,0,-1,1};
    string str;

    // 풀이 // 
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> str;
        for (size_t s = 0; s < str.size(); ++s) {
            map[i][s] = str[s] - '0';
        }
    }

    que.push(make_pair(0,0));

    // bfs //
    while (!que.empty()) {
        int a = que.front().first;
        int b = que.front().second;
        que.pop();
        check_visited[a][b] = true;

        for (size_t s = 0; s < 4; ++s) {
            int n = a + da[s];
            int m = b + db[s];

            if ((n >= 0 && n < N && m >= 0 && m < M) && map[n][m] == 1 && !check_visited[n][m]) {
                check_visited[n][m] = true;
                length[n][m] = length[a][b] + 1;
                que.push (make_pair(n,m));
            }
        }
    }

    cout << length[N-1][M-1];
    return 0;

    // dp 풀듯이 경로의 길이를 저장하면서 진행 // 
}