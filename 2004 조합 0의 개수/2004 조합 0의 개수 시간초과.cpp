#include <iostream>
#define ll long long
using namespace std;

// 시간 초과 // 

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll cnt_two = 0, cnt_five = 0;

    int n,m;
    cin >> n >> m;

    for (int i = n-m; i <= n; ++i) {
        int tmp = i;
        while (true) {
            if (tmp % 2 == 0) {
                cnt_two++;
                tmp /= 2;
            } else break;
        }

        while (true) {
            if (tmp % 5 ==0) {
                cnt_five++;
                tmp /= 5;
            } else break;
        }
    }

    for (int j = 2; j < n-m; ++j) {
        int tmp = j;
        while (true) {
            if (tmp % 2 == 0) {
                cnt_two--;
                tmp /= 2;
            } else break;
        }

        while(true) {
            if (tmp % 5 == 0) {
                cnt_five--;
                tmp /= 5;
            } else break;
        }
    }

    long long ans = min (cnt_two,cnt_five);
    if (ans < 0) cout << 0;
    else cout << ans;
    return 0;
}