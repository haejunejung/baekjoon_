// S1 < S2 < ... < Sk > Sk+1 > ... > Sn
// 수열이 주어졌을 떄, 수열의 부분 수열 중 가장 긴 바이토닉 수열의 길이를 구해라.

#include <iostream>
#include <vector>
#define Max 1000
#define Up 0
#define Down 1

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[Max] = { }, dp_up[Max] = { }, dp_down[Max] = { };
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        dp_up[i] = 1;
        dp_down[i] = 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp_up[i] = max(dp_up[j]+1, dp_up[i]);
            }
        }
    }

    for (int i = N-1; i >=0; --i) {
        for (int j = N-1; j > i; --j) {
            if (arr[i] > arr[j]) {
                dp_down[i] = max(dp_down[j]+1, dp_down[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max (dp_up[i]+dp_down[i]-1,ans);
    }

    cout << ans;
    return 0;
}