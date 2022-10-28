#include <iostream>

using namespace std;

int rec_sum (int n, int res) {
    if (n < 1) return res;
    else return rec_sum(n-1, res+n);
}

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int res = rec_sum(n, 0);
    cout << res;

    return 0;
}