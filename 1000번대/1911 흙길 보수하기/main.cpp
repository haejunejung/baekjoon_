#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N, L;
pair <int,int> waterhole[10000];

bool compare (pair <int,int> &a, pair <int,int> &b) {
    return a.first < b.first;
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        waterhole[i] = make_pair(start, end);
    }

    sort (waterhole, waterhole+N, compare);
}

void solution () {
    int count = 0;
    unsigned long long route = 0;
    for (int i = 0; i < N; ++i) {
        if (route < waterhole[i].first) route = waterhole[i].first;

        while (1) {
            if (route >= waterhole[i].second) break;
            route += L;
            count++;
        }
    }

    cout << count;
}

int main (void) {
    input ();
    solution ();
    return 0;
}