#include <iostream>

using namespace std;

int GCD (int a, int b) {
    if (b == 0) return a;
    else return GCD (b, a % b);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    unsigned long long val = 1;
    int minimum = 1000001;
    int maximum = 0;

    while (N--) {
        int n;
        cin >> n;

        val = val * n / GCD(val, n);
        if (n < minimum) minimum = n;
        if (n > maximum) maximum = n;
    }

    if (maximum == val) {
        val *= minimum;
    }

    cout << val << endl;

    return 0;
}