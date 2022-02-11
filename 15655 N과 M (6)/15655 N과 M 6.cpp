#include <iostream>
#include <algorithm>

#define Max 9

using namespace std;

int N, M;
int arr[Max] = { }, ans[Max] = { };
bool check_[Max] = { };

void Solution (int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (check_[cnt] == false) {
            if (cnt == 0) {
                check_[cnt] = true;
                ans[cnt] = arr[i];
                Solution(cnt+1);
                check_[cnt] = false;
            }

            else {
                if (arr[i] > ans[cnt-1]) {
                    check_[cnt] = true;
                    ans[cnt] = arr[i];
                    Solution(cnt+1);
                    check_[cnt] = false;
                }
            }
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    Solution (0);
}