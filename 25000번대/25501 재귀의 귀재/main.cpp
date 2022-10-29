#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, testcase;
    cin >> T;
    for (testcase=1; testcase<=T; testcase++) {
        string S;
        cin >> S;

        int l = 0;
        int r = S.length() - 1;
        int c = 0;
        bool flag = true;

        while (l <= r) {
            c++;

            if (S[l++] != S[r--]) {
                flag = false;
                break;
            }
        }

        if (flag && S.length() % 2 == 0) c++;

        cout << (flag ? 1 : 0) << " " << c << "\n";
    }
    return 0;
}
