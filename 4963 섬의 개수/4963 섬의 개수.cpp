#include <iostream>
#include <queue>

#define Max 50

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int da[8] = {-1,-1,-1,0,0,1,1,1};
    int db[8] = {-1,0,1,-1,1,-1,0,1};

    queue <int> ans;
    while (true) {
        int w,h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int map[Max][Max];
        bool check_visited[Max][Max] = {false};
        queue < pair<int,int> > que;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        for (size_t i = 0; i < h; ++i) {
            for (size_t j = 0; j < w; ++j) {
                if (map[i][j] == 1 && !check_visited[i][j]) {
                    cnt++;
                    check_visited[i][j] = true;
                    que.push (make_pair(i,j));

                    while (!que.empty()) {
                        int a = que.front().first;
                        int b = que.front().second;
                        que.pop();

                        for (size_t s = 0; s < 8; ++s) {
                            int x = a + da[s];
                            int y = b + db[s];

                            if ((x >= 0 && x < h && y >= 0 && y < w) && map[x][y] == 1 && !check_visited[x][y]) {
                                check_visited[x][y] = true;
                                que.push(make_pair(x,y));
                            }
                        }
                    }
                }
            }
        }
        ans.push(cnt);
    }

    while (!ans.empty()) {
        cout << ans.front() << '\n';
        ans.pop();
    }

    return 0;
}