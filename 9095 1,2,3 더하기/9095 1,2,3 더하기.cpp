// 1,2,3의 합으로 정수 n을 만드는 경우의 수 구하기
#include <iostream>
#define Max 11
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    int dp[Max] = { };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; ++i) {
        for (int j = i - 3; j < i; ++j) {
            dp[i] += dp[j];
        }
    }

    for (int i = 0; i < testcase; ++i) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}