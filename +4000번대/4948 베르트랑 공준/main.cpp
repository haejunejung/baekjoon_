#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool primeNum[246913]; /* n의 최댓값 * 2 개수만큼의 배열 생성 */
    fill_n(primeNum, 246913, true);
    primeNum[0] = false; primeNum[1] = false; /* 0,1은 소수가 아니다 */

    for (int i = 2; i <= 246912; ++i) { /* 소수 check */
        if (primeNum[i]) {
            for (int j = i+i; j <= 246912; j+=i) {
                primeNum[j] = false;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; /* 0이 나오면 종료 */

        int count = 0;
        for (int i = n+1; i <= 2*n; ++i) { /* n보다 크고 2n보다 작거나 같으면 count++ */
            if (primeNum[i]) count++;
        }

        cout << count << "\n"; /* 각 n에 대한 소수 개수 출력 */
    }

    return 0;
}