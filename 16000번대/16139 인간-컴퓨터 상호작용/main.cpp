#include <iostream>
#include <cstring>

int countAlphaSum[200000][26];

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(countAlphaSum, 0, sizeof(countAlphaSum));

    string S; 
    size_t q, now, i, j;

    cin >> S >> q;

    

    for (i = 0; i < S.size(); ++i) {
        now = S[i] - 'a';

        if (i == 0) {
            countAlphaSum[i][now]++;
            continue;
        }

        for (j = 0; j < 26; ++j) {
            countAlphaSum[i][j] = countAlphaSum[i-1][j];
        }
        countAlphaSum[i][now]++;

    }

    for (size_t i = 0; i < q; ++i) {
        char alpha;
        size_t l, r, s1, s2;
        
        cin >> alpha >> l >> r;

        now = alpha - 'a';

        s1 = l == 0 ? 0 : countAlphaSum[l-1][now];
        s2 = countAlphaSum[r][now];

        cout << s2 - s1 << "\n";
    }

    return 0;
}




