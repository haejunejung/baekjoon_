#include <iostream>
#include <algorithm>

bool Compare (std::pair<int, int> p1, std::pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    } else return p1.first < p2.first;
}

int main () {
    using namespace std;

    int N;
    cin >> N;

    std::pair<int, int> MAP[100000];
    for (int i = 0; i < N; ++i) {
        cin >> MAP[i].first >> MAP[i].second;
    }

    sort (MAP, MAP + N, Compare);

    for (int i = 0; i < N; ++i) {
        cout << MAP[i].first << " " << MAP[i].second << '\n';
    }

    return 0;
}