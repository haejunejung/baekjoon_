#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A, B, res;
    cin >> A >> B;

    reverse(A.begin(), A.end()); /* string A를 뒤집는다 */
    reverse(B.begin(), B.end()); /* string B를 뒤집는다 */

    size_t length, i;
    size_t lenA = A.length();
    size_t lenB = B.length();

    /* length는 A와 B의 길이 중 작은 값으로 초기화 이후 while을 위해서 */
    if (lenA > lenB) length = lenB;
    else length = lenA;

    int pass_over = 0; /* 올림수 */
    int remainder = 0; /* 나머지수 */

    for (i = 0; i < length; ++i) {
        int sum = (A[i] - '0') + (B[i] - '0') + pass_over;

        pass_over = sum / 10;
        remainder = sum % 10;

        res += char(remainder + '0');
    }

    if (lenA > lenB) {
        while (i < lenA) {
            int sum = (A[i] - '0') + pass_over;

            pass_over = sum / 10;
            remainder = sum % 10;

            res += char(remainder + '0');
            i++;
        }
    }
    else if (lenA < lenB) {
        while (i < lenB) {
            int sum = (B[i] - '0') + pass_over;

            pass_over = sum / 10;
            remainder = sum % 10;

            res += char(remainder + '0');
            i++;
        }
    }

    if (pass_over > 0) res += char(pass_over + '0');

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}