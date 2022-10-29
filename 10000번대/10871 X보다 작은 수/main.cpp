#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase, num, X;
    cin >> T >> X;

    /* 굳이 배열에 저장하지 않고도 출력이 가능하기 때문에, 배열을 만들지 않았다 */
    for (testcase = 1; testcase <= T; testcase++) {
        cin >> num;
        if (num < X) {
            cout << num << " ";
        }
    }

    return 0;
}