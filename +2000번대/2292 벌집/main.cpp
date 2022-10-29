#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 1
    // 1+6
    // 1+6+12
    // 1+6+12+18 
    // 1+6+12+18+24 ...
    // 1+6(n(n+1)/2)

    int N;
    cin >> N;

    int n = 0;
    while (true) {
        if (1 + 3 * n * (n+1) >= N) break;
        n++;
    }

    cout << n+1;

    return 0;
}