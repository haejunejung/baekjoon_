#include <iostream>
#include <queue>

using namespace std;

// using queue && array //
// not using priority queue // 
// priority queue -> +1966.cpp //

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; ++i) {
        int N, M;
        cin >> N >> M;

        queue < pair<int,int> > que;
        int arr[10] = { }, find , cnt = 1;
        for (int index = 0; index < N; ++index) {
            int data;
            cin >> data;

            pair<int,int> x;
            x.first = data;
            x.second = index;

            que.push(x);
            arr[data]++;
            if (index == M) find = data;
        }

        for (int j = 9; j > find; --j) {
            while(true) {
                if (arr[j] == 0) break;
                if (que.front().first == j) {
                    arr[j]--;
                    que.pop();
                    cnt++;
                } else {
                    que.push(que.front());
                    que.pop();
                }
            }
        }

        while (true) {
            if (que.front().first == find && que.front().second == M) break;
            if (que.front().first == find && que.front().second != M) {
                que.pop();
                cnt++;
            } else {
                que.push(que.front());
                que.pop();
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}