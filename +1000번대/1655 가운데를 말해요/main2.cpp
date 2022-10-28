#include <iostream>
#include <queue>
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq_gre;
    priority_queue<int, vector<int>, less<>> pq_les;

    // N == 1 일 때 //
    if (N == 1) {
        int a;
        cin >> a;
        cout << a;
        return 0;
    }

    // N >= 2 일 때 처음 두 개를 먼저 넣고 시작 //
    int a,b;
    cin >> a >> b;
    if (a > b) {
        pq_gre.push(a);
        pq_les.push(b);
    } else {
        pq_gre.push(b);
        pq_les.push(a);
    }

    cout << a << '\n' << pq_les.top() << '\n';

    // N > 2 일 때, 작은 큐(pq_les) 항상 개수가 1개 많거나 동일하게 유지하면서
    // pq_les의 가장 위 (max)를 출력한다.
    for (int i = 2; i < N; ++i) {
        int n;
        cin >> n;

        if (n <= pq_gre.top()) pq_les.push(n);
        else pq_gre.push(n);

        if (pq_les.size() > pq_gre.size() + 1) {
            pq_gre.push(pq_les.top());
            pq_les.pop();
        } else if (pq_les.size() < pq_gre.size()) {
            pq_les.push(pq_gre.top());
            pq_gre.pop();
        }

        cout << pq_les.top() << '\n';

    }

    return 0;
}