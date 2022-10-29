#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string A,B;
    cin >> A >> B;

    bool flag = false;
    for (int i = 2; i >= 0; i--) {
        int a = A[i] - '0';
        int b = B[i] - '0';

        if (a > b) {
            flag = false;
            break;
        }
        else if (a < b) {
            flag = true; 
            break;
        }
        else continue;
    }

    if (!flag) {
        for (int i = 2; i >= 0; i--) {
            cout << A[i];
        }
    }
    else {
        for (int i = 2; i >= 0; i--) {
            cout << B[i];
        }
    }

    return 0;
}