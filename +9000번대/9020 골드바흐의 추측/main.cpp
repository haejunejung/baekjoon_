#include <iostream>

using namespace std;

void goldbach (int n, bool primeNum []) {
    int min = 10001, max = 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (primeNum[i] && primeNum[n-i]) { /* i 과 n-i가 모두 소수라면, */
            if (abs((n-i)-i) < abs(max - min)) { /* 차가 작은게 나오면, min과 max의 수를 바꾼다 */
                min = i;
                max = n-i;
            }
        }
    }

    /* 출력 후 return */
    cout << min << " " << max << endl;
    return;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    /* 소수 저장하기 */
    bool primeNum[10001];
    fill_n(primeNum, 10001, true);
    primeNum[0] = false;
    primeNum[1] = false;

    for (int i = 2; i <= 10000; ++i) {
        if (primeNum[i]) {
            for (int j = i+i; j <= 10000; j+=i) {
                primeNum[j] = false;
            }
        }
    }

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase) {
        int n;
        cin >> n;

        /* 골드바흐 파티션 찾기 */
        goldbach (n, primeNum);
    }

    return 0;
}