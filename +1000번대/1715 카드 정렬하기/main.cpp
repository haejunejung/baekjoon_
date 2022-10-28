#include <iostream>
#include <queue>
#include <vector>

int main () {
    using namespace std;
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans << endl;

    return 0;
}