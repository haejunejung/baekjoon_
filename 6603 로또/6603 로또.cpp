// 1 ~ 49 pick 6 num
// S, k 가 주어졌을 때, 경우의 수를 구하기
// S는 오름차순으로 주어진다

#include <iostream>
#define Max 50

using namespace std;

int n, arr[Max] = { }, ans[Max] = { };
bool visited[Max] = { }, check_[Max] = { };

void Solution (int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (visited[cnt] == false && check_[arr[i]] == false ){
            if (cnt == 0) {
                visited[cnt] = true; check_[arr[i]] = true;
                ans[cnt] = arr[i];
                Solution(cnt+1);
                visited[cnt] = false; check_[arr[i]] = false;
            } else {
                if (ans[cnt-1] < arr[i]) {
                    visited[cnt] = true; check_[arr[i]] = true;
                    ans[cnt] = arr[i];
                    Solution(cnt+1);
                    visited[cnt] = false; check_[arr[i]] = false;
                }
            }
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        Solution(0);
        cout << '\n';
    }
}
