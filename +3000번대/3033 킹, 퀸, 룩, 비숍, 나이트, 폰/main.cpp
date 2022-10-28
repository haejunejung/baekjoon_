#include <iostream>

int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int chess[ ] = {1, 1, 2, 2, 2, 8};
    int count;
    for (int i = 0; i < 6; ++i) {
        cin >> count;
        cout << chess[i] - count << " ";
    }

    return 0;
}