#include <iostream>
#include <queue>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<>> plus_pq;
    priority_queue<int, vector<int>, greater<>> minus_pq;

    int one_count = 0;
    int zero_count = 0;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num > 1) plus_pq.push(num);
        else if (num == 1) one_count++;
        else if (num == 0) zero_count++;
        else minus_pq.push(num);
    }

    long long ans = 0;
    while (!plus_pq.empty()) {
        if (plus_pq.size() > 1) {
            int temp = plus_pq.top();
            plus_pq.pop();
            ans += temp * plus_pq.top();
            plus_pq.pop();
        } else {
            ans += plus_pq.top();
            plus_pq.pop();
        }
    }

    int last = 0;

    while (!minus_pq.empty()) {
        if (minus_pq.size() > 1) {
            int temp = minus_pq.top();
            minus_pq.pop();
            ans += temp * minus_pq.top();
            minus_pq.pop();
        } else {
            last = minus_pq.top();
            minus_pq.pop();
        }
    }

    if (zero_count == 0) ans += last;
    if (one_count > 0) ans += one_count;

    cout << ans;

    return 0;
}