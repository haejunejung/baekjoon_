#include <iostream>
#include <algorithm>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int *A = new int[n];
    int *B = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    sort(A, A+n, less<>());
    sort(B, B+n, greater<>());

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += A[i] * B[i];
    }

    cout << sum;

    return 0;
}