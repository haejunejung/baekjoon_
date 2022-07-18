#include <iostream>

int N,K;
int W[101], V[101];
int dp[101][100001];

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (j-W[i] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], V[i] + dp[i-1][j-W[i]]);
            }
        }
    }

    cout << dp[N][K];
    

    return 0;
}