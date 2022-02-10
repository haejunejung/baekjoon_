#include <iostream>

using namespace std;

int N, M;
bool check_[9] = { };
int arr[9] = { };

void Solution (int cnt) {
    if (cnt == M) {
        bool check = true;
        for (int i = 0; i < M-1; ++i) {
            if (arr[i] > arr[i+1]) {
                check = false;
            }
        }

        if (check == true) {
            for (int i = 0; i < M; ++i) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (check_[i] == false) {
            check_[i] = true;
            arr[cnt] = i;
            Solution(cnt+1);
            check_[i] = false;
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    Solution (0);
    return 0;
}