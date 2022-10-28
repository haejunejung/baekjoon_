#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define Max 25

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt;
    int da[4] = {-1,1,0,0};
    int db[4] = {0,0,-1,1};
    bool check_visited[Max][Max] = {false};
    string map[Max];

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    int ans[Max*Max] = {0}, house = 0;
    queue < pair<int,int> > que;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == '1' && !check_visited[i][j]) {
                cnt = 0;
                check_visited[i][j] = true;
                que.push(make_pair(i,j));

                while (!que.empty()) {
                    ans[house]++;
                    int a = que.front().first;
                    int b = que.front().second;

                    que.pop();

                    for (int k = 0; k < 4; ++k) {
                        int x = a + da[k];
                        int y = b + db[k];

                        if ((x >= 0 && y >= 0 && x < N && y < N) && map[x][y] == '1' && !check_visited[x][y]) {
                            check_visited[x][y] = true;
                            que.push(make_pair(x,y));
                        }
                    }
                }
                house++;
            }
        }
    }

    sort (ans, ans+house);
    cout << house << '\n';
    for (size_t s = 0; s < house; ++s) {
        cout << ans[s] << '\n';
    }
    return 0;

}