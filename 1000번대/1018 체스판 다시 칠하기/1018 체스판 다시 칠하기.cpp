#include <iostream>
#include <string>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };

    string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };

    
    int Res = 63;
    for (int i = 0; i <= N-8; ++i) {
        for (int j = 0; j <= M-8; ++j) {
            int a = 0, cnt_BW = 0, cnt_WB = 0;
            for (int k = i; k < i + 8; ++k) {
                int b = 0;
                for (int l = j; l < j + 8; ++l) {
                    if (arr[k][l] != BW[a][b]) {
                        cnt_BW++;
                    }

                    if (arr[k][l] != WB[a][b]) {
                        cnt_WB++;
                    }
                    b++;
                }
                a++;
            }
            if (Res > min(cnt_BW,cnt_WB)) Res = min(cnt_BW,cnt_WB);
        }

    }

    cout << Res;
    return 0;

    
}