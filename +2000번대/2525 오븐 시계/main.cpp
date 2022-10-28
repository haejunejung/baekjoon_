#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    int H, M;
    H = C / 60; /* 요리하는데 걸리는 hour */
    M = C - (C/60) * 60; /* 요리하는데 걸리는 minute */

    if (B+M < 60) {
        H = (A+H) % 24;
        M = B+M;
    }
    else {
        H = ((A+H) + (B+M) / 60) % 24;
        M = (B+M) % 60;
    } 

    cout << H << " " << M << endl;

    return 0;
}