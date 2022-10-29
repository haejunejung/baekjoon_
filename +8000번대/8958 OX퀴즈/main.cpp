#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; testcase++) {
        string quiz;
        cin >> quiz;

        int continuous_count = 0, score = 0;

        for (int i = 0; i < quiz.length(); i++) {
            if (quiz[i] == 'X') continuous_count = 0;
            else {
                continuous_count++;
                score += continuous_count;
            }
        }
        cout << score << "\n";
    }

    return 0;
}