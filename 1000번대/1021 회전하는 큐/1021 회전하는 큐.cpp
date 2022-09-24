#include <iostream>
#include <deque>

using namespace std;

deque <int> dq;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0;
    cin >> N >> M;

    // Deque에 숫자 넣어두기
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; ++i) {
        int n, idx;
        cin >> n;

        for (int j = 0; j < dq.size(); ++j) {
            if (dq[j] == n) {
                idx = j;
                break;
            }
        }

        if (idx < dq.size() - idx) {
            // Movetoleft();

            while (true) {
                if (dq.front() == n) break;
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } else {
            // Movetoright();

            while(true) {
                if (dq.front() == n) break;
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
    }

    cout << cnt;
    return 0;
}