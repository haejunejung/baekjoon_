#include <iostream>
#define Max 501

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[Max][Max] = { };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=i; ++j) {
            cin >> dp[i][j];
        }
    }

    int max_ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j];
            max_ans = max(dp[i][j],max_ans);
        }
    }

    cout << max_ans;
    return 0;
}
