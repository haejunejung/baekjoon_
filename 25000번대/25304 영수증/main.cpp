#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int X, N, a, b, price = 0;
    cin >> X >> N;

    while (N--) {
        cin >> a >> b;
        price += a*b;
    }

    if (X == price) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}