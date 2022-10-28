#include <iostream>
#include <queue>
#include <utility>

// using queue && priority_queue STL //

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int N, M, cnt = 1;
        cin >> N >> M;

        queue < pair<int,int> > que;
        priority_queue <int> pq;
        pair <int,int> couple;

        for (int index = 0; index < N; ++index) {
            int num;
            cin >> num;

            couple.first  = num;
            couple.second = index;

            que.push(couple);
            pq.push(num);
        }

        while (true) {
            int data = que.front().first;
            int idx  = que.front().second;
            que.pop();

            if(pq.top() == data) {
                if (idx == M) break;
                pq.pop();
                cnt++;

            } else {
                couple.first  = data;
                couple.second = idx;
                que.push(couple);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}