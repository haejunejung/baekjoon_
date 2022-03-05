#include <iostream>
#include <queue>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {-2,-1,1,2,-2,-1,1,2};

    for (int i = 0; i < testcase; ++i) {

        int l;
        cin >> l;

        int map[l][l];
        bool check_visited[l][l];
        for (size_t i = 0; i < l; ++i) {
            for (size_t j = 0; j < l; ++j) {
                map[i][j] = 0;
                check_visited[i][j] = false;
            }
        }

        int x, y;
        cin >> x >> y;

        int m, n;
        cin >> m >> n;

        queue < pair<int,int> > que;
        que.push(make_pair(x,y));
        check_visited[x][y] = true;
        while (!que.empty()) {
            int a = que.front().first;
            int b = que.front().second;
            que.pop();

            if (a == m && b == n) {
                cout << map[a][b] << '\n';
                break;
            }

            for (size_t k = 0; k < 8; ++k) {
                int nx = a + dx[k];
                int ny = b + dy[k];

                if (nx >= 0 && nx < l && ny >= 0 && ny < l && !check_visited[nx][ny]) {
                    check_visited[nx][ny] = true;
                    map[nx][ny] = map[a][b] + 1;
                    que.push(make_pair(nx,ny));
                }
            }
        }

    }

    return 0;
}