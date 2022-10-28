#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase, A, B;
    cin >> T;

    for (testcase = 1; testcase <= T; testcase++) {
        cin >> A >> B;
        cout << A+B << "\n";
    }

    return 0;
}