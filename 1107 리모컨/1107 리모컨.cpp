// current channel 100 
// 0 ~ 9 + -
// broken button ..

#include <iostream>
#include <string>
#define inf -10000000

using namespace std;

string N;

int Plus_Minus (int channel, int cnt) {
    int value = stoi(N);
    while (channel != value) {
        if (channel < value) {
            channel++;
        } else {
            channel--;
        }
        cnt++;
    }

    return cnt;
}

int Solution (int arr[], int channel, int cnt) {
    int ans = 0;
    return 0;

}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int channel = 100, M;
    cin >> N >> M;

    // 가지고 있는 버튼
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    // 고장난 버튼 inf로 고정
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        arr[num] = inf;
    }

    // 최대한 가까운 수로 버튼으로 이동하고, + - 로 변경해서 원하는 채널로 갈 수 있도록..
    int just_plus_minus = Plus_Minus (channel,0);
    cout << just_plus_minus << '\n';

    int ans = Solution (arr,channel,0);
    cout << ans << '\n';

    cout << min(just_plus_minus, ans);
    return 0;   
}