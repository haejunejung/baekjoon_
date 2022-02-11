#include <iostream>
#define Max 100000
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp_up[Max] = { }, dp_down[Max] = { }, dp[Max] = { };
    for (int i = 0; i < n; ++i) {
        cin >> dp_up[i];
        dp_down[i] = dp_up[i];
    }

    int ans = dp_up[0];
    for (int i = 1; i < n; ++i) {
        dp_up[i] = max (dp_up[i-1] + dp_up[i], dp_up[i]);
        ans = max (ans ,dp_up[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        dp_down[i] = max (dp_down[i+1] + dp_down[i], dp_down[i]);
    }

    dp[0] = dp_up[0];
    dp[n-1] = dp_down[n-1];
    for (int i = 1; i < n - 1; ++i) {
        dp[i] = dp_up[i-1] + dp_down[i+1];
    }

    for (int i = 1; i < n; ++i) {
        if (ans < dp[i]) ans = dp[i];
    }

    cout << ans;
    return 0;
}