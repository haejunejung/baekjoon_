#include <iostream>

typedef unsigned long long ull;

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    ull cnt[1000] = { };
    ull pSum = 0, ans = 0, input;

    while (n--) {
        cin >> input;
        pSum = (pSum + input) % m;

        cnt[pSum]++;
    }   

    ans += cnt[0];
    while (m--) {
        ull tempCnt = cnt[m];
        ans += tempCnt * (tempCnt - 1) / 2;
    }

    cout << ans;
    return 0;
}