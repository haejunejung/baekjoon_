#include <iostream>
#define Max 500

using namespace std;

int x_length, y_length, ans = 0, map[Max][Max];
bool check_[Max][Max];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int exception_case[4][4][2] = { 
    {{0,0},{0,-1},{0,1},{-1,0}},
    {{0,0},{-1,0},{1,0},{0,1}},
    {{0,0},{0,-1},{0,1},{1,0}},
    {{0,0},{-1,0},{1,0},{0,-1}}
};

void DFS (int x, int y, int sum, int cnt) {
    if (cnt == 4) {
        ans = max (ans, sum);
        return;
    }

    for (int i = 0; i < 4; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) continue;
        if (!check_[ny][nx]) {
            check_[ny][nx] = true;
            DFS (nx, ny, sum+map[ny][nx], cnt+1);
            check_[ny][nx] = false;
        }
    }
}

void Exception (int x, int y) {
    for (int i = 0; i < 4; ++i) {
        bool flag = false;
        int sum = 0;

        for (int j = 0; j < 4; ++j) {
            int nx = x + exception_case[i][j][1];
            int ny = y + exception_case[i][j][0];

            if (nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) {
                flag = true;
                break;
            }

            sum += map[ny][nx];
        }

        if (flag == false) {
            ans = max (ans, sum);
        }
    }

}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> y_length >> x_length;

    for (int y = 0; y < y_length; ++y) {
        for (int x = 0; x < x_length; ++x) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < y_length; ++y) {
        for (int x = 0; x < x_length; ++x) {
            DFS(x,y,0,0);
            Exception(x,y);
        }
    }
    cout << ans;
    return 0;
}