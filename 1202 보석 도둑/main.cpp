#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    priority_queue<int> price;
    std::pair<int,int> *info = new std::pair<int,int>[N];
    int *bag = new int[K];

    for (int i = 0; i < N; ++i) {
        int M,V;
        cin >> M >> V;
        info[i].first = M;
        info[i].second = V;
    }

    for (int i = 0; i < K; ++i) {
        cin >> bag[i];
    }

    sort(info, info+N, less<>());
    sort(bag, bag+K, less<>());

    long long max_sum = 0;
    int idx = 0;

    for (int i = 0; i < K; ++i) {
        while (idx < N && info[idx].first <= bag[i]) {
            price.push(info[idx++].second);
        }

        if (!price.empty()) {
            max_sum += (long long)price.top();
            price.pop();
        }
    }

    cout << max_sum;
    return 0;
}