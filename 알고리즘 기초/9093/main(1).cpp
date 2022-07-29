
/* 1차 시도 -> 정답은 되었으나 속도가 너무 느리다 */
#include <iostream>

#define integer int
#define character char

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    integer T, testcase;
    cin >> T;
    cin.ignore();

    for (testcase=1; testcase<=T; testcase++) {
        character ch[1001]; /* string 대신 char 배열로 풀어보았다 */
        cin.getline(ch, 1001, '\n');

        integer count = 0;
        while (ch[count]) {
            count++;
        }

        ch[count] = ' '; /* 마지막에 빈 칸을 넣음으로써, 빈 칸이 나올 때마다 뒤집어서 출력하는 조건을 만들었다 */

        integer left = 0, right; /* left : 단어의 첫 문자 // right : 단어 마지막 글자 뒤의 빈 칸 */ 
        for (right=0; right <= count; ++right) {
            if (ch[right] == ' ' && right < count) {
                for (integer i = right-1; i >= left; --i) {
                    cout << ch[i];
                }
                left = right+1; /* 빈 칸 다음 문자를 가리키도록 만들었다 */
                cout << " "; /* 위의 출력문은 단어를 뒤집은 것만 출력하게 하고, 띄어쓰기를 따로 할 수 있도록 하였다 */ 
            }

            else if (ch[right] == ' ' && right == count) { /* 문장의 마지막 글자의 경우, 뒤에 띄어쓰기를 할 필요가 없어서 따로 설정하였다 */
                for (integer i = right-1; i >= left; --i) {
                    cout << ch[i];
                }
            }
        }

        cout << endl;
    }
}