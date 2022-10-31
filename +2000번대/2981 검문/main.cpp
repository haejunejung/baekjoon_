#include <iostream>
#include <algorithm>
#include <vector>

int GCD (int a, int b) {
    if (b == 0) return a;
    else return GCD (b, a%b);
}

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector <int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;

        v.push_back(val);
    }

    sort(v.begin(), v.end());

    int gcd = v[1] - v[0];
    for (int i = 2; i < N; ++i) {
        gcd = GCD(gcd, v[i] - v[i-1]);
    }

    vector <int> res;
    for (int i = 2; i*i <= gcd; ++i) {
        if (gcd % i == 0) {
            res.push_back(i);
            res.push_back(gcd/i);
        }
    }

    res.push_back(gcd);

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (auto iter : res) {
        cout << iter << " ";
    }

    return 0;
}