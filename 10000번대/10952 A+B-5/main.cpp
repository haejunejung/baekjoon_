#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B;

    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0) break;
        cout << A+B << "\n";
    }

    return 0;
}