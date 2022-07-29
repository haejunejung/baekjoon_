#include <iostream>
#include <cstring>
#include <stack>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;
    cin.ignore(); /* 버퍼 삭제 */

    for (testcase=1; testcase<=T; testcase++) {
        string sentence; /* 문자열 입력 받기 */
        cin >> sentence;

        bool VPS = true; /* VPS */

        stack <char> st; /* '(' 문자를 받을 stack 생성 */
        for (size_t i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == '(') {
                st.push(sentence[i]);
            } else if (sentence[i] == ')' && st.empty()) { /* ')'에 맞춰질 '('가 stack에 없다면 VPS 조건 만족하지 않는다. */
                VPS = false;
                break;
            } else { /* 쌍이 맞춰져서 stack에서 하나 빼주기 */
                st.pop();
            }
        }

        if (!st.empty()) { /* 모든 쌍이 맞춰졌다면 stack이 비어있을 것이고, 그렇지 않다면 stack에 남아있을 것이므로 VPS 만족하지 못한다. stack에 남아있는 것들도 모두 빼준다.(안해도 무방) */
            VPS = false;
            while (!st.empty()) {
                st.pop();
            }
        }

        if (VPS) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}