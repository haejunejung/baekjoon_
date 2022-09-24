#include <iostream>
#include <queue>
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, cnt = 0;
    cin >> N >> K;

    queue <int> que;
    for (int i = 1; i <= N; ++i) {
        que.push(i);
    }

    cout << '<';
    while (true) {
        for (int i=0; i<K-1; ++i) {
            que.push(que.front());
            que.pop();
        }
        cout << que.front();
        que.pop();
        if (!que.empty()) cout << ", ";
        else break;
    }
    cout << '>';
    return 0;
}