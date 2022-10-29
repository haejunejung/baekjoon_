#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase) {
        int H, W, C;
        cin >> H >> W >> C;

        int a = C / H; /* 호수 를 결정하기 위한 값 */
        int b = C % H; /* 나머지가 있다면 -> 다음 호수, 없다면 -> 지금 호수 */

        if (b == 0) { /* 현재 호수, 층은 H 그대로 */
            if (a < 10) {
                cout << H << 0 << a << endl;
            }
            else {
                cout << H << a << endl;
            }
        }
        else { /* 다음 호수 (a = a + 1), 층은 b로 바뀐다 */
            a++;
            if (a < 10) {
                cout << b << 0 << a << endl;
            }
            else {
                cout << b << a << endl;
            }
        }
    }

    return 0;
}