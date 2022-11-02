#include <iostream>

#define ll long long
#define MAX 41

using namespace std;

size_t cnt_rec;
size_t cnt_dp;

ll fibo_rec (int n) {
    if (n == 1 || n == 2) {
        cnt_rec++;
        return 1;
    }
    else return fibo_rec(n-1) + fibo_rec(n-2);
}

ll fibo_dp (int n) {
    ll val[MAX];
    val[1] = 1;
    val[2] = 1;

    for (size_t i = 3; i <= n; ++i) {
        val[i] = val[i-1] + val[i-2];
        cnt_dp++;
    }

    return val[n];
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    fibo_rec(n);
    fibo_dp(n);

    cout << cnt_rec << " " << cnt_dp << endl;

    return 0;
}