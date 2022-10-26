#include <iostream>

int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A,B;
    cin >> A >> B;

    cout << A+B << '\n' << A-B << '\n' << A*B << '\n' << A/B << '\n' << A%B << endl;

    return 0;
}