#include <iostream>

int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned int a,b,res;
    cin >> a >> b;
    res = a*b;
    while (true) {
        cout << a * (b%10) << endl;
        if (b/10 == 0) break;
        b /= 10;
    }

    cout << res;

    return 0;
}