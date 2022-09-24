#include <iostream>

using namespace std;

int GCD (int x, int y) {
    if (x % y == 0) {
        return y;
    } else {
        return GCD(y, x % y);
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        long long sum = 0;
        for (int k = 0; k < n - 1; ++k) {
            for (int l = k + 1; l < n; ++ l) {
                sum += GCD(arr[k],arr[l]);
            }
        }

        cout << sum << '\n';
    }
    return 0;
}