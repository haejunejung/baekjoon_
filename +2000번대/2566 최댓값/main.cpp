#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i, j;
    int table[9][9];

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            cin >> table[i][j];
        }
    }

    int max = -1, max_i = 0, max_j = 0;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (max < table[i][j]) {
                max = table[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << max << "\n" << max_i+1 << " " << max_j+1 << endl;

    return 0;
}