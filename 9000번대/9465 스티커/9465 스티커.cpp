// 공유하는 스티커는 모두 찢어진다.
// 점수의 합이 최대가 되도록 스티커를 떼어낸다.

#include <iostream>
#define Up   0 
#define Down 1
#define Max  100000

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int n;
        cin >> n;

        int arr[Max][2] = { };
        for (int j = 0; j < n; ++j) {
            cin >> arr[j][0];
        }

        for (int k = 0; k < n; ++k) {
            cin >> arr[k][1];
        }

        int dp[Max][2] = { };
        dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1];
        dp[1][0] = dp[0][1] + arr[1][0]; dp[1][1] = dp[0][0] + arr[1][1];

        int max_number = max (dp[1][0], dp[1][1]);
        for (int i = 2; i < n; ++i) {
            dp[i][0] = max (max (dp[i-2][0], max(dp[i-2][1], dp[i-1][1])) + arr[i][0], dp[i-1][0]);
            dp[i][1] = max (max (dp[i-2][0], max(dp[i-2][1], dp[i-1][0])) + arr[i][1], dp[i-1][1]);
            max_number = max (max_number, max(dp[i][0], dp[i][1]));
        }

        cout << max_number << '\n';
        
    }
    return 0;
}


// 붙였는지 안붙였는지 2개의 배열로 구분 ? 
// 전전번째의 위 아래 + 이전 위 아래 dp확인하여 최댓값 ?
// 전전꺼의 위, 아래, 전꺼의 대각선이 붙어있고 현재가 붙을 때,
// 전꺼의 바로 옆이 붙었을 떄 