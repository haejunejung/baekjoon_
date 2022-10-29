#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    bool primeNum[10001];
    fill_n(primeNum, 10001, true); /* primeNum 배열 초기화 */
    primeNum[0] = false;
    primeNum[1] = false; /* 0,1은 소수가 아니다 */
    
    for (int i = 2; i <= 10000; ++i) { /* 소수 찾기 */
        if (primeNum[i]) {
            for (int j = i+i; j <= 10000; j += i) {
                primeNum[j] = false; /* 소수가 아니면 check */
            }
        }
    }

    unsigned long long sum = 0; /* 소수의 합 */
    unsigned int min = 10001; /* 소수 최솟값 */
    for (int i = M; i <= N; ++i) {
        if (primeNum[i]) {
            sum += i;
            if (i < min) min = i;
        }
    }

    if (min == 10001) cout << -1; /* 최솟값이 변하지 않는다 -> 소수가 없다 */
    else cout << sum << "\n" << min;

    return 0;
}