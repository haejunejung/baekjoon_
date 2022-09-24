#include <iostream>
#include <vector>

int main (void) {
    using namespace std;

    int n;
    cin >> n;
    vector <int> dp(n,0);
    
    for (int i = 0; i < n; ++i) {
        cin >> dp[i];
    }

    // version 1 // 
    // int max_sum = dp[0];
    // for (int i = 1; i < n; ++i) {
    //     dp[i] = max(dp[i], dp[i-1] + dp[i]);
    //     max_sum = max(dp[i], max_sum);
    // }

    // std::cout << max_sum << std::endl;

    // version 2 //
    int max_sum = dp[0];
    for (int i = 1; i < n; ++i) {
        if (dp[i] < 0) 
    }

    return 0;
}