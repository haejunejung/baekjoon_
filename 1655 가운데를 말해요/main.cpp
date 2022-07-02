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

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (pq_gre.size() == pq_les.size()) pq_les.push(num);
        else pq_gre.push(num);

        if ((!pq_gre.empty() && !pq_les.empty()) && (pq_gre.top() < pq_les.top())) {
            int max = pq_les.top();
            int min = pq_gre.top();
            pq_les.pop();
            pq_gre.pop();
            pq_les.push(min);
            pq_gre.push(max);
        }

        cout << pq_les.top() << '\n';
    }

    return 0;
}