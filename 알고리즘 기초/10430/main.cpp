#include <iostream>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    cout << (A+B) % C << endl;
    cout << ((A%C) + (B%C)) % C << endl;
    cout << (A*B) % C << endl;
    cout << ((A%C) * (B%C)) % C << endl;

    return 0;
}