#include <iostream>
#define Max 1000
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[Max] = { } , dp[Max] = { };
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int ans = 0;
    for (int i = N-1; i >= 0; --i) {
        for (int j = N-1; j > i; --j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        ans = max (dp[i],ans);
    }

    cout << ans;
    return 0;
}