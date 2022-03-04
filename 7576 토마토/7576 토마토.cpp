#include <iostream>
#include <queue>

#define Max 1000

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, count = 0, ans = 0;
    int map[Max][Max] = {0};
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue < pair<int,int> > que;

    cin >> M >> N;

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                que.push (make_pair(i,j));
            }

            if (map[i][j] == 1 || map[i][j] == -1) ++count;
        }
    }

    // 모두 익어 있는 경우 // 
    if (count == N * M) {
        cout << 0;
        return 0;
    }
    

    // bfs // 
    while (!que.empty()) {
        for (size_t s = 0; s < que.size(); ++s) {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (size_t i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if ((nx >= 0 && nx < M && ny >= 0 && ny < N) && map[ny][nx] == 0) {
                    map[ny][nx] = map[y][x] + 1;
                    que.push(make_pair(ny,nx));
                }

            }
        }
    }

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {

            // 익지 않는 토마토가 존재하는 경우 //
            if (map[i][j] == 0) {
                cout << -1;
                return 0;
            }

            ans = max (ans, map[i][j]);
        }
    }

    // -1 해주는 이유는 map의 익어있는 토마토의 시작이 1이기 때문에 // 
    cout << (ans-1);
    return 0;

    
}