#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    if (B >= C) { /* 손익 분기점이 존재하지 않을 때 */
        cout << -1;
        return 0;
    }

    cout << A / (C-B) + 1;



    return 0;
}