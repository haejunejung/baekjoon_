#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int X;
    cin >> X;

    int n = 1;

    while (true) { /* 몇 번째 대각선에 존재하는지 찾는 반복문 */
        if (X <= (n * (n+1)) / 2) break;
        n++;
    }

    int count = (n * (n-1)) / 2 + 1; /* X가 존재하기 바로 전의 대각선까지 총 합 */

    if (n % 2 == 0) { /* 짝수 번째 대각선이면, */
        for (int i = 1; i <= n; ++i) { /* 오른쪽 위에서 왼쪽 밑으로 대각선 */
            if (count == X) {
                cout << i << '/' << n-i+1 << endl;
                break;
            }
            count++;
        }
    }
    else { /* 홀수 번째 대각선이면, */
        for (int i = n; i >= 1; --i) { /* 왼쪽 밑에서 오른쪽 위로 대각선 */
            if (count == X) {
                cout << i << '/' << n-i+1 << endl;
                break;
            }
            count++;
        }
    }

    return 0;
}