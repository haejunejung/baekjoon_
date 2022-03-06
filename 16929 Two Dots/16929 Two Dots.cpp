// 도저히 틀리는 곳을 찾을 수가 없어서 계속 지웠다가 다시 쓰고를 반복했는데
// Yes No를 YES NO로 쓰고 있었다. 바보같다.
// 이런 실수를 반복하지 않도록 ..
#include <iostream>
#include <cstring>

#define endl "\n"
#define Max 50

using namespace std;

int N,M;
char MAP[Max][Max];
bool Visit[Max][Max];
bool flag = false;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input () {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> MAP[i][j];
        }
    }
}

void DFS (int x, int y, int dir, int line_cnt, int Sx, int Sy) {
    if (flag == true) return;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (Visit[nx][ny] == false) {
                if (MAP[nx][ny] == MAP[x][y]) {
                    Visit[nx][ny] = true;
                    if (i == dir) DFS (nx, ny, dir, line_cnt, Sx, Sy);
                    else DFS (nx, ny, i, line_cnt + 1, Sx, Sy);
                }
            }

            else {
                if (nx == Sx && ny == Sy && line_cnt >= 4) {
                    flag = true;
                    return;
                }
            }
        }
    }
}

void Solution () {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            memset (Visit, false, sizeof(Visit));
            int Start_X = i;
            int Start_Y = j;

            for (int k = 0; k < 4; ++k) {
                memset (Visit, false, sizeof(Visit));
                Visit[i][j] = true;
                DFS (i, j, k, 1, Start_X, Start_Y);

                if (flag == true) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "No" << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();

    return 0;
}