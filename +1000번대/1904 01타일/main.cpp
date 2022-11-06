#include <iostream>

#define MAX 1000001
using namespace std;

long long dp[MAX];
int N;

void make_dp () {
    int i;

    dp[1] = 1;
    dp[2] = 2;
    for(i=3; i<MAX; ++i)    
        dp[i] = (dp[i-2] + dp[i-1]) % 15746;
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
}

int main (void) {
    input ();
    make_dp ();
    cout << dp[N];

    return 0;
}