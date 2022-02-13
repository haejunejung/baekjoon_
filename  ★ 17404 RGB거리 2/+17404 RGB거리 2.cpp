#include <iostream>
#define Max 1001
#define red 0
#define green 1
#define blue 2
#define inf 1000 * 1000 + 1

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int rgb[Max][3], dp[Max][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> rgb[i][j];
        }
    }

    int ans = inf;
    for (int i = 0; i < 3; ++i) {
        dp[0][red] = inf;
        dp[0][green] = inf;
        dp[0][blue] = inf;
        dp[0][i] = rgb[0][i];

        for (int j = 1; j < n; ++j) {
            dp[j][red] = min(dp[j-1][green], dp[j-1][blue]) + rgb[j][red];
            dp[j][green] = min(dp[j-1][red], dp[j-1][blue]) + rgb[j][green];
            dp[j][blue] = min(dp[j-1][red], dp[j-1][green]) + rgb[j][blue];
        }

        for (int k = 0; k < 3; ++k) {
            if (i == k) continue;
            ans = min (ans, dp[n-1][k]);
        }    
    }

    cout << ans;
    return 0;
}