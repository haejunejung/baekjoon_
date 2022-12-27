#include <iostream>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;

    long dp[100001], maximum = 0;
    fill_n(dp, 100001, 0);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        dp[i+1] = dp[i] + num;
    }

    maximum = dp[K];
    for (int i = K+1; i <= N; ++i) {
        maximum = max(maximum, dp[i] - dp[i-K]);
    }

    cout << maximum;

    return 0;
}