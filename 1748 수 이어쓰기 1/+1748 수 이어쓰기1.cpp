#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int risingspot = 1, digit = 1, cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (i == risingspot * 10) {
            risingspot*=10;
            digit++;
        }
        cnt += digit;
    }

    cout << cnt;
    return 0;
}