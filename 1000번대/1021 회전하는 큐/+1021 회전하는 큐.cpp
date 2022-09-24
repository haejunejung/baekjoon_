#include <iostream>
#include <deque>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, sum = 0;
    cin >> N >> M;

    deque <int> dq;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        deque <int> tmp_dq1 = dq;
        deque <int> tmp_dq2 = dq;

        int cnt1 = 0, cnt2 = 0;
        while (true) {
            if (tmp_dq1.front() == num) break;
            tmp_dq1.push_back(tmp_dq1.back());
            tmp_dq1.pop_front();
            cnt1++;
        }

        while (true) {
            if (tmp_dq2.front() == num) break;
            tmp_dq2.push_front(tmp_dq1.front());
            tmp_dq2.pop_back();
            cnt2++;
        }

        if (cnt1 < cnt2) {
            dq = tmp_dq1;
            sum += cnt1 ;

        } else {
            dq = tmp_dq2;
            sum += cnt2 ;
        }

        dq.pop_front();
    }

    cout << sum;
    return 0;
}