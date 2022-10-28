#include <iostream>
#include <vector>

int main (void) {
    using namespace std;
    unsigned int N;
    cin >> N;

    vector <unsigned int> dp(N+1); // vector가 아닌 배열을 사용해도 상관 x //
    dp[1] = 0;

    // Bottom -up //

    for (unsigned int i = 2; i <= N; ++i) {
        // 우리가 고려해야 하는 것 : dp[i-1] , dp[i/2] , dp[i/3] 중 가장 작은 수 + 1 //

        // dp[i-1] // 
        dp[i] = dp[i-1];

        // dp[i/2] // 
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2]);

        // dp[i/3] // 
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3]);

        // 셋 중 가장 작은 수 + 1 // 
        dp[i] = dp[i] + 1;
    }
    
    std::cout << dp[N] << std::endl;

    return 0;

}