#include <iostream>

#define MAX 101
using namespace std;

long long dp[MAX];
int T;

void make_dp () {
    /* 
        1 1 1 2 2 3 4 5 7 9 12 16 21 28 37 49 64 ...
        위의 순서대로 진행하게 되는데, 규칙성을 확인해보면 
        i번째 수는 i-1번째 수와 i-5번째 수를 더하는 것을 알 수 있다
        i-5번째 수가 존재해야하기 때문에, 1~5번째 수는 Basis step에 해당한다   
        이후 6번째 이상의 수는 recursive step을 통해 구한다
    */
    int i;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;

    for (i=11; i<MAX; ++i) {
        dp[i] = dp[i-1] + dp[i-5];
    }
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
}

int main (void) {
    make_dp ();
    input ();
    
    while (T--) {
        int N;
        cin >> N;

        cout << dp[N] << "\n";
    }


    return 0;
}

/* 
    주의할 점 : dp를 int형으로 선언했을 경우, dp[100]에서 -203165375라는 수가 나온다 
    즉, 범위를 벗어나게 되므로 다른 형을 사용해야 한다. 위의 예시에서는 long long형을 사용하였다
*/