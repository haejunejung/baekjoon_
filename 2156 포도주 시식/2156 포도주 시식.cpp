// 포도주 잔 선택 -> 마신 후 제자리
// 연속 3잔 마실수 x
// 되도록 많은 양의 포도주를 마시고 싶음
// 1~n 번호에 각 포도주 양이 주어짐

#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[10001];
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    int dp[10001];
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];

    for (int i = 3; i <= N; ++i) {
        dp[i] = max (max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]),dp[i-1]);
    }

    cout << dp[N];
    return 0;

}