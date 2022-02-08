#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[1001], dp[1001];
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
        ans = max(dp[i],ans);
    }

    cout << ans;
    return 0;

}

