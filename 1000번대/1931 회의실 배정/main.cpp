#include <iostream>
#include <algorithm>
#include <utility>

#define Max 100000

int main (void) {
    using namespace std;

    unsigned int N;

    cin >> N;

    std::pair <unsigned int, unsigned int> time[Max];
    for (unsigned int i = 0; i < N; ++i) {
        unsigned int x, y;
        cin >> x >> y;
        time[i].second = x;
        time[i].first = y;
    }

    sort(time, time + N);

    unsigned int cnt = 0, end_time = 0;

    for (unsigned int i = 0; i < N; ++i) {
        if (time[i].second >= end_time) {
            end_time = time[i].first;
            cnt++;
            // cout << end_time << '\n';
        }
    }

    cout << cnt;

    return 0;

    
    
}