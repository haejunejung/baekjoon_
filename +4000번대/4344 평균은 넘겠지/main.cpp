#include <iostream>
#include <iomanip>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase) {
        int N, cnt_aboveAvg = 0;
        cin >> N;

        int score[1000];
        double avg = 0.0;

        for (int i = 0; i < N; ++i) { /* score 받고, 평균 구하기 위해 다 더한다 */
            cin >> score[i];
            avg += score[i];
        }

        avg /= N;

        for (int i = 0; i < N; ++i) {
            if (score[i] > avg) cnt_aboveAvg++; /* 평균 넘는 사람 수 check */
        }

        cout << fixed;
        cout.precision(3);
        cout << (double(cnt_aboveAvg) / N) * 100 << "%" << "\n";
    }



    return 0;
}