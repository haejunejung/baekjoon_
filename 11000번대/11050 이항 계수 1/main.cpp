#include <iostream>

using namespace std;

int factorial (int n, int res) {
    if (n == 1) return res;
    else return factorial(n-1, n *res);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    long long res = 1;

    for (int i = K+1; i <= N; ++i) {
        res *= i;
    }

    for (int i = 1; i <= N-K; ++i) {
        res /= i;
    }

    cout << res;

    return 0;
}