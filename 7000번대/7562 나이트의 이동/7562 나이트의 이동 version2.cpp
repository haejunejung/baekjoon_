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

    while (testcase--) {

        int l;
        cin >> l;

        // reset // 
        int map[l][l];
        for (size_t i = 0; i < l; ++i) {
            for (size_t j = 0; j < l; ++j) {
                map[i][j] = 0;
            }
        }

        int x, y;
        cin >> x >> y;

        int m, n;
        cin >> m >> n;

        // bfs // 
        queue < pair<int,int> > que;
        que.push(make_pair(x,y));
        while (!que.empty()) {
            y = que.front().first;
            x = que.front().second;
            if (y == m && x == n) break;
            que.pop();

            // 각각의 방향 // 
            for (size_t k = 0; k < 8; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // 범위 안에 들어갈 떄 //
                if ((nx >= 0 && nx < l && ny >= 0 && ny < l) ) {
                    
                    // 한 번도 가지 않았을 떄 //
                    if (map[ny][nx] == 0) {
                        map[ny][nx] = map[y][x] + 1;
                        que.push(make_pair(ny,nx));
                    } 
                    
                    // 한 번 거쳐갈 가능성 ? 
                    else {
                        if (map[ny][nx] < (map[y][x] + 1)) continue;
                        else if (map[ny][nx] > (map[y][x] + 1)) {
                            map[ny][nx] = map[y][x] + 1;
                            que.push(make_pair(ny,nx));
                        }
                    }
                }
            }
        }

        cout << map[m][n] << '\n';

    }

    return 0;
}