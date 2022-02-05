#include <iostream>
#include <queue>

using namespace std;

// using STL queue // 

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;

    queue <int> que;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        if (str == "push") {
            cin >> num;
            que.push(num);
        }

        else if (str == "pop") {
            if (que.empty()) cout << -1 << '\n';
            else {
                cout << que.front() << '\n';
                que.pop();
            }
        }

        else if (str == "size") {
            if (que.empty()) cout << 0 << '\n';
            else cout << que.size() << '\n';
        }

        else if (str == "empty") {
            if (que.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        else if (str == "front") {
            if (que.empty()) cout << -1 << '\n';
            else cout << que.front() << '\n';
        }

        else if (str == "back") {
            if (que.empty()) cout << -1 << '\n';
            else cout << que.back() << '\n';
        }
    }

    return 0;
}