#include <iostream>

using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase, n, count_num = 0;
    bool student[31]; /* 제출 했는지 안했는지 확인하는 배열 */
    int nosubmit_student[2]; /* 제출 안한 학생의 출석번호 저장 (2개)*/
    fill_n(student, 31, false); /* 처음에 모두 제출 안했다고 초기화 하고 제출한 사람 체크 */

    for (testcase = 1; testcase <= 28; testcase++) {
        cin >> n;
        student[n] = true;
    }

    for (testcase = 1; testcase <= 30; testcase++) {
        if (student[testcase] == false) {
            nosubmit_student[count_num++] = testcase;
        }
    }

    cout << min(nosubmit_student[0], nosubmit_student[1]) << "\n" << max(nosubmit_student[0], nosubmit_student[1]) << endl;

    return 0;
}