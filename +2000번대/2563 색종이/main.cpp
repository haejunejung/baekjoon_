#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool table[101][101] = { };

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase) {
        int x,y;
        cin >> x >> y;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                table[y+i][x+j] = true;
            }
        }
    }

    int area = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (table[i][j]) area++;
        }
    }

    cout << area;

    return 0;
}