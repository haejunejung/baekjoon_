#include <iostream>
#include <stack>
#include <queue>

int main () {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    bool IsPossible = true; /* 수열이 만들어질 수 있는지 확인하는 boolean */
    stack <int> st; /* 1~n까지의 수를 차례로 넣기 위한 stack : FILO structure */
    queue <char> q; /* '+' 와 '-'의 결과값을 넣기 위한 queue : FIFO structure */
    

    int sequence = 1; /* n까지 오름차순으로 올리는 수 */

    for (int cnt = 1; cnt <= n; ++cnt) {
        int num; /* n개의 수를 받는다 */
        cin >> num;

        if (sequence <= num) { /* 만약 오름차순으로 오르는 수와 크거나 같다면 push */
            while (sequence <= num) {
                st.push(sequence);
                q.push('+');
                sequence++;
            }
            st.pop(); /* 해당 수까지 push했기 때문에, 해당 수는 pop */
            q.push('-');
        } else if (sequence > num) {
            if (!st.empty() && st.top() == num) { /* 비어있지 않고, top이 해당 수와 같다면 pop */
                st.pop();
                q.push('-');
            } else { /* 비어있지 않은데, top이 해당 수와 다르다면 수열이 만들어 질 수 없다 */
                IsPossible = false;
                break;
            }
        }
    }

    while (!st.empty()) { /* stack에 남아있는 수들 없애주기 */
        st.pop();
    }

    if (IsPossible) {
        while (!q.empty()) { /* 결과값 출력 */
            cout << q.front() << '\n';
            q.pop();
        }
    } else { /* Impossible */
        cout << "NO" << '\n';
    }

    return 0; /* 종료 */
}