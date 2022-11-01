#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    int Combination[31][31] = { };
    Combination[1][0] = 1;
    Combination[1][1] = 1;

    for (int i = 2; i <= 30; ++i) {
        Combination[i][0] = 1;
        Combination[i][i] = 1;
        
        for (int j = 1; j < i; ++j) {
            Combination[i][j] = Combination[i-1][j] + Combination[i-1][j-1];
        }
    }

    for (testcase=1; testcase<=T; ++testcase) {
        int N, M;
        cin >> N >> M;

        cout << Combination[M][N] << "\n";
    }

    return 0;
}