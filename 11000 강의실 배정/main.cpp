#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

bool sort_second (const std::pair<int,int> &a, const std::pair<int,int> &b) {
    return a.second < b.second;
}

int main () {
    using namespace std;

    int N;
    cin >> N;

    vector<pair<int,int>> v;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end());

    // sort(v.begin(), v.end(), [](const auto &x, const auto &y) {return x.second < y.second;});
    // sort(v.begin(), v.end(), sort_second);

    // for (int i = 0; i < N; ++i) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    priority_queue<int ,vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        if (pq.empty()) pq.push(v[i].second);
        else {
            if (pq.top() <= v[i].first) pq.pop();
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << endl;

    
    return 0;

}