#include <iostream>
#define Max 9

using namespace std;

int N, M;
bool check_[Max] = { };
int arr[Max] = { };

void Solution (int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (check_[cnt] == false) {
            if (cnt == 0) {
                check_[cnt] = true;
                arr[cnt] = i;
                Solution(cnt+1);
                check_[cnt] = false;
            } else {
                if (i >= arr[cnt-1]) {
                    check_[cnt] = true;
                    arr[cnt] = i;
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

    cin >> N >> M ;
    Solution (0);
}