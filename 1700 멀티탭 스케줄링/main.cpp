#include <iostream>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K,count=0;
    cin >> N >> K;

    int *input = new int[K];
    int *plug = new int[N];
    fill_n(plug, N, 0);

    for (int i = 0; i < K; ++i) 
        cin >> input[i];

    for (int i = 0; i < K; ++i) {
        bool pluggedIn = false;
        int element = input[i];
        for (int j = 0; j < N; ++j) {
            if (plug[j] == element) {
                pluggedIn = true;
                break;
            }
        }

        if (pluggedIn) continue;

        for (int j = 0; j < N; ++j) {
            if (!plug[j]) {
                plug[j] = element;
                pluggedIn = true;
                break;
            }
        }

        if (pluggedIn) continue;

        int idx, deviceIdx = -1;
        for (int j = 0; j < N; ++j) {
            int lastIdx = 0;
            for (int k = i + 1; k < K; ++k) {
                if (plug[j] == input[k]) break;
                lastIdx++;
            }

            if (lastIdx > deviceIdx) {
                idx = j;
                deviceIdx = lastIdx;
            }
        }
        plug[idx] = element;
        count++;
    }

    cout << count;

    return 0;
}