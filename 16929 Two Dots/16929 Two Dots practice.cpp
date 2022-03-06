#include <iostream>
#include <cstring>

#define Max 50

using namespace std;

int n, m;
char map[Max][Max];
bool visit[Max][Max];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void Input () {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
}

void dfs (int x, int y, int target_x, int target_y, int count) {
    visit[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (!visit[nx][ny]) {
                if (map[x][y] == map[nx][ny]) {
                    dfs (nx, ny, target_x, target_y, count + 1);
                }
            } 
            else {
                if (target_x == nx && target_y == ny && count >= 4) {
                    cout << "Yes";
                    exit(0);
                }
            }
        }
    }

    visit[x][y] = false;
}

void Solution () {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visit[i][j]) {
                int target_x = i;
                int target_y = j;

                dfs (i, j, target_x, target_y, 1);
                visit[i][j] = true;
            }
        }
    }

    cout << "No";
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input ();
    Solution ();

    return 0;

}