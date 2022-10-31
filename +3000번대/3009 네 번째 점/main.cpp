#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int pointX[3];
    int pointY[3];

    int X = 0, Y = 0;

    for (int i = 0; i < 3; ++i) {
        cin >> pointX[i] >> pointY[i];
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (pointX[i] == pointX[j]) {
                X = pointX[i];
            }

            if (pointY[i] == pointY[j]) {
                Y = pointY[i];
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (X != pointX[i]) {
            X = pointX[i];
            break;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (Y != pointY[i]) {
            Y = pointY[i];
            break;
        }
    }

    cout << X << " " << Y << endl;

    return 0;
}