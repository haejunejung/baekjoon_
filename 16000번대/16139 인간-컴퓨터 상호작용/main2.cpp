#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <size_t> v[26];
    string S;
    size_t q, now, i, j;

    cin >> S >> q;
    
    for (size_t i = 0; i < S.size(); ++i) {
        now = S[i] - 'a';

        v[now].push_back(i);
    }

    for (size_t i = 0; i < q; ++i) {
        char alpha;
        size_t l, r;

        cin >> alpha >> l >> r;
        
        now = alpha - 'a';

        auto s1 = lower_bound(v[now].begin(), v[now].end(), l);
        auto s2 = upper_bound(v[now].begin(), v[now].end(), r);

        cout << s2 - s1 << "\n";
    }
    return 0;
}