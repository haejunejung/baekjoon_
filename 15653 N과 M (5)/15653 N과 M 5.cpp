#include <iostream>
#include <algorithm>

#define Max 9

using namespace std;

int N, M;
bool check_[Max] = { }; // 각 자리에 숫자가 들어가 있는지 체크하는 배열
bool check_arr[Max] = { }; // arr에 들어간 숫자가 사용되었는지 체크하는 배열
int ans[Max] = { }; // 각 자리에 숫자를 넣을 배열
int arr[Max] = { }; // 입력으로 숫자를 받을 배열

void Solution (int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (check_[cnt] == false && check_arr[i] == false) { 
            check_[cnt] = true; check_arr[i] = true;
            ans[cnt] = arr[i];
            Solution (cnt+1);
            check_[cnt] = false; check_arr[i] = false;    
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
    return 0;

}