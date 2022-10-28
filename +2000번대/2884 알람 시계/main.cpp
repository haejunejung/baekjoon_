#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int H, M;
    cin >> H >> M;

    if (H == 0 && M < 45) {
        H = 23;
        M = 60 - (45-M);
    }
    else if ((H > 0 && H < 24) && M < 45) {
        H--;
        M = 60 - (45-M);
    }
    else {
        M = M - 45;
    }

    cout << H << " " << M << endl;

    return 0;
}