#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; testcase++) {
        int R;
        cin >> R;

        string S;
        cin >> S;

        string res;
        for (size_t i = 0; i < S.length(); ++i) {
            for (int j = 0; j < R; ++j) {
                res += S[i];
            }
        }
        cout << res << "\n";
    }

    return 0;
}