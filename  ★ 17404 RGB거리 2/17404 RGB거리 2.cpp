// 빨강, 초록, 파랑 중 하나의 색으로 색칠한다
// 각각의 집을 빨강 초록 파랑으로 칠하는 비용이 주어진다
// 1번집의 색은 2,N번 집의 색과 다르다
// N번집의 색은 N-1,1번 집의 색이 다르다
// i번째 집의 색은 i-1, i+1번의 집의 색과 다르다
// 모든 집을 칠하는 최소비용을 구해라

#include <iostream>
#include <string>
#define Max 1000
#define R 0
#define G 1
#define B 2
#define inf 1000 * 1000 + 1
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int color[Max][3] = { }, dp[Max][3] = { }, ans = inf;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> color[i][j];
        }
    }

    for (int rgb = 0; rgb < 3; ++rgb) {
        for (int i = 0; i < 3; ++i) {
            if (rgb == i) {
                dp[0][rgb] = color[0][rgb];
            } else {
                dp[0][i] = inf;
            }
        }

        for (int j = 1; j < N; ++j) {
            dp[j][R] = min(dp[j-1][B], dp[j-1][G]) + color[j][R];
            dp[j][B] = min(dp[j-1][R], dp[j-1][G]) + color[j][B];
            dp[j][G] = min(dp[j-1][R], dp[j-1][B]) + color[j][G];
        }

        for (int k = 0; k < 3; ++k) {
            if (rgb == k) {
                continue;
            } else {
                ans = min (ans, dp[N-1][k]);
            }
        }
    }

    cout << ans;
    return 0;

}