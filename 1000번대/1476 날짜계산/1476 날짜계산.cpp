// 1 < E < 15
// 1 < S < 28 
// 1 < M < 19

#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int e = 1, s = 1, m = 1, year = 1;
    while (true) {
        if (e == E && s == S && m == M) break;
        if (e >= 1 && e < 15) {
            e++;
        } else {
            e = 1;
        }

        if (s >= 1 && s < 28) {
            s++;
        } else {
            s = 1;
        }

        if (m >= 1 && m <19) {
            m++;
        } else {
            m = 1;
        }
        year++;
    }

    cout << year;
    return 0;
}