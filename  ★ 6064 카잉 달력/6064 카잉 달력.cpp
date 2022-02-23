#include <iostream>

using namespace std;


void Solution (int M, int N, int x, int y) {
    bool flag = false;
    for (int k = x; k < M*N; k += M) {
        int tempy = k % N;
        if (tempy == 0) tempy = N;
        if (tempy == y) {
            cout << k << '\n';
            flag = true;
            break;
        }
    }

    if (flag == false) cout << -1 << '\n';
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        Solution(M, N, x, y);
    }

    return 0;
}