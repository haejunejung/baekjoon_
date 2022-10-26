#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B, count = 0;
    cin >> A >> B;

    if (B == A) { /* 처음 입력 받을 때 같다면 최솟값 0 + 1 = 1 */
        cout << 1;
        return 0;
    }

    while (B > A) { /* B값을 계속 줄일 것이므로 B가 A보다 작아지는 경우는 B와 A가 같아질 수 없다 */
        if (B % 10 == 1) B /= 10; /* 일의 자리가 1이라면 나누기 10을 통해서 1없애기 */
        else {
            if ((B % 10) % 2 == 1) break; /* 홀수는 2로 나눌 수 없으므로 바로 break를 걸어서 -1 출력 */
            else B /= 2; /* 짝수면 2로 나눠서 다음 진행 */
        }
        count ++;
    }

    if (B == A) cout << count + 1; /* 최솟값 + 1 출력 */
    else cout << -1; /* 안되는 경우 -1로 출력 */

    return 0;
}