#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    int A,B,C;
    
    A = T / 300;
    T %= 300;

    B = T / 60;
    T %= 60;

    C = T / 10;
    T %= 10;

    if (T == 0) cout << A << " " << B << " " << C;
    else cout << -1;

    return 0;
}