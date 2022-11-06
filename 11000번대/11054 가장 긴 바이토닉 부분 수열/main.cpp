#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i, j, N, val[1000], dp[1000];
    cin >> N;

    fill_n(dp, 1000, 1); /* 모든 부분의 최소 개수는 1개이므로 1로 초기화 */

    for(i=0; i<N; ++i) {
        cin >> val[i]; /* 수를 받아준다 */
    }

    /* 증가하는 부분 수열 */
    for(i=1; i<N; ++i) {
        for(j=i-1; j>=0; --j) {
            if (val[i] > val[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    /* 감소하는 부분 수열 */
    for(i=1; i<N; ++i) {
        for(j=i-1; j>=0; --j) {
            if(val[i] < val[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    /* 최장 길이 구하기 */
    int maximum = dp[0];
    for(i=1; i<N; ++i) {
        maximum = max(maximum, dp[i]);
    }

    cout << maximum;
    return 0;
}