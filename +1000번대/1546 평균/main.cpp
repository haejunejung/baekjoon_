#include <iostream>
#include <iomanip>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase, num, max_score = 0;
    cin >> T;

    double score[1000];
    for (testcase = 0; testcase < T; testcase++) {
        cin >> num;
        score[testcase] = num;
        if (max_score < num) max_score = num;
    }

    double sum = 0;
    for (testcase = 0; testcase < T; testcase++) {
        sum += (score[testcase] / max_score) * 100;
    }

    cout << setprecision(16);
    cout << sum / T;

    return 0;
}