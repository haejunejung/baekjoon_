#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, val;
    vector <int> v;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> val;

        v.push_back(val);
    }

    sort(v.begin(), v.end());

    cin >> M;

    for (int i = 1; i <= M; ++i) {
        cin >> val;

        auto upper = upper_bound(v.begin(), v.end(), val);
        auto lower = lower_bound(v.begin(), v.end(), val);

        cout << upper - lower << " ";
    }

    return 0;
}