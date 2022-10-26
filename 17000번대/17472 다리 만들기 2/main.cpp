#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define MAX 987654321

int N, M;
int res;
int board[10][10];

vector <pair<int,int>> bridgeStrat; /* 시작점 */
vector <pair<int,int>> bridgeEnd; /* 도착점 */
vector <pair<int,int>> connectIsland; /* 다리로 연결되는 섬의 정보 */
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    }

    res = MAX;
}

void MakeIsland () { /* 섬들 구분하는 함수 */
    int Island = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 1) {
                Island++;
                queue <pair<int,int>> q;
                q.push(make_pair(i,j));

                while (!q.empty()) {
                    int initX = q.front().second;
                    int initY = q.front().first;
                    q.pop();

                    board[initY][initX] = Island;
                    for (int k = 0; k < 4; ++k) {
                        int nextX = initX + dx[k];
                        int nextY = initY + dy[k];
                        if (nextX < 0 || nextX > M || nextY < 0 || nextY > N) continue;
                        if (board[nextY][nextX] == 1) q.push(make_pair(nextY, nextX));
                    }
                }
            } 
        }
    }
}

void MakeBridge () { /* 만들어질 수 있는 다리 만들기 */
    for (int i = 0; i < N; ++i) {
        for (int j = 0 ; j < M; ++j) {
            if (board[i][j] > 1) {
                for (int k = 0; k < 4; ++k) {
                    int nearX = j + dy[k];
                    int nearY = i + dx[k];
                    if (nearX < 0 || nearX > M || nearY < 0 || nearY > N) continue;
                    if (board[nearY][nearX] == 0) {
                        break;
                    }
                }
            }
        }
    }
}

void solution () {
    MakeIsland ();
    MakeBridge ();

    if (res == MAX) cout << -1;
    else cout << res;
}

int main (void) {
    input ();
    solution ();
    return 0;
}