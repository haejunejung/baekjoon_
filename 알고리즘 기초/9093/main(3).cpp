/* 3차 시도 -> 라이브러리 이용 속도가 확연하게 빨라진 것을 확인할 수 있었다 */
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
    cin.ignore();

    for (testcase=1; testcase<=T; ++testcase) {
        string sentence;
        getline(cin, sentence);

        sentence += ' ';

        stack <char> st;

        for (int i = 0; i <= sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }

                cout << " ";
            } else {
                st.push(sentence[i]);
            }
        }

        cout << '\n';
    }

    return 0;
}