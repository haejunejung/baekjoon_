#include <iostream>

using namespace std;

void rec (int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) cout << " ";
    else if (n == 1) cout << "*";
    else rec (i, j, n/3);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rec(i, j, N);
        }
        cout << "\n";
    }

    return 0;
}