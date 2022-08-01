/* 1회 시도 - 시간초과 */
#include <iostream>
#include <cstring>

#define left 'L'
#define right 'D'
#define del 'B'
#define ins 'P'

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sentence;
    cin >> sentence;

    int T, testcase;
    cin >> T;

    int cursor = sentence.size(); /* 커서가 문장의 맨 뒤에서 시작 */

    for (testcase=1; testcase<=T; ++testcase) {
        char command;
        cin >> command;

        if (command == left) {
            if (cursor > 0) cursor--; /* 커서를 왼쪽으로 한 칸 옮김*/
        } else if (command == right) {
            if (cursor < sentence.size()) cursor++;  /* 커서를 오른쪽으로 한 칸 옮김*/
        } else if (command == del) {
            if (cursor > 0) sentence.erase(--cursor,1); /* 커서 왼쪽 문자 삭제*/
        } else { /* command == insert */
            char newCharacter;
            cin >> newCharacter;

            sentence.insert(cursor++, 1, newCharacter); /* 문자를 커서 왼쪽에 추가함 */
        }
    }

    cout << sentence;
    return 0;
}