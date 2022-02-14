// 0~N 정수 K개로 합이 N이 되는 경우의 수 찾기
// 순서가 바뀐 경우, 다른 경우로 센다
// 한개의 수를 여러번 사용 가능하다

#include <iostream>
#define Max 201
#define mod 1000000000
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long dp[Max][Max] = { }; // n, k
    for (int i = 0; i <= n; ++i) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= j; ++l) {
                dp[j][i] += dp[l][i-1];
                dp[j][i] %= mod;
            }
        }
    }

    cout << dp[n][k];
    return 0;
}

// n = 0 + n = ... = n + 0의 상황
// k-1개로 0~n을 만드는 경우의 수를 합치면 k개로 n을 만드는 경우의 수가 나옴
// 처음에 k가 1개일 때, 모두 1개로 초기화 시킨 후 k가 2개 이상일 때를 구하면 됨.
// 이 때, n은 0부터 시작해야 함. 왜냐하면 0 0 0 1 이런 식으로 시작점이 0인 경우가 있어서..
