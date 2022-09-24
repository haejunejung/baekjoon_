#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[8], ans[8];
bool check[8];

void Solution (int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check[cnt] == false) {
            if (cnt == 0) {
                check[cnt] = true;
                ans[cnt] = arr[i];
                Solution(cnt+1);
                check[cnt] = false;

            } else {
                if (ans[cnt-1] <= arr[i]) {
                    check[cnt] = false;
                    ans[cnt] = arr[i];
                    Solution(cnt+1);
                    check[cnt] = false;
                }
            }
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    Solution (0);

    return 0;

}