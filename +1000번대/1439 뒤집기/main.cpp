#include <iostream>
#include <cstring>

using namespace std;

int setZero (string S) {
    int idx = 0, count = 0;
    while (idx < S.length()) {
        if (S[idx] == '1') {
            while (idx < S.length()) {
                if (S[idx] == '0') break;
                idx++;
            }
            count++;
        }
        idx++;
    }

    return count;
}

int setOne (string S) {
    int idx = 0, count = 0;
    while (idx < S.length()) {
        if (S[idx] == '0') {
            while (idx < S.length()) {
                if (S[idx] == '1') break;
                idx++;
            }
            count++;
        }
        idx++;
    }

    return count;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S;
    cin >> S;

    int countZero = setZero(S); /* 모두 0으로 만들 때의 횟수 */
    int countOne = setOne(S); /* 모두 1로 만들 때의 횟수 */

    cout << min(countZero, countOne);


    return 0;
}