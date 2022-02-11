// 연속된 몇 개의 수를 선택하여 최대 합을 구하기
// 수열에서 수 하나를 제거가능
// 최소 1개이상 선택

#include <iostream>
#define Max 100000

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[Max][2] = { } , arr[Max] = { };
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i][0] = dp[i][1] = arr[i];
    }

    int MaxNumber = arr[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max (dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max (dp[i-1][0], dp[i-1][1] + arr[i]);
        MaxNumber = max (MaxNumber, max(dp[i][0],dp[i][1]));
    }

    cout << MaxNumber;
    return 0;
}