#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    unsigned long long apartment[15][15]; /* 각 호수에 사는 사람 수 저장할 배열 */

    for (int i = 1; i <= 14; ++i) { /* 0층의 i호에는 i명이 산다 */
        apartment[0][i] = i;
    }

    for (int i = 1; i <= 14; ++i) {  /* 각 호수에 사는 사람 수 저장하는 함수 */
        for (int j = 1; j <= 14; ++j) {
            
            unsigned long long sum = 0;
            for (int k = 1; k <= j; ++k) {
                sum += apartment[i-1][k];
            }

            apartment[i][j] = sum;
        }
    }

    for (testcase=1; testcase<=T; ++testcase) {
        int n,k;
        cin >> n >> k;

        cout << apartment[n][k] << "\n";
    }

    return 0;
}