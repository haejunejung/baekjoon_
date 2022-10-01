#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N,M;
vector <pair<int,int>> info;

bool compare (pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }

    return a.second < b.second;
}

void input () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        int weight, money;
        cin >> weight >> money;

        info.push_back(make_pair(weight, money));
    }

    sort (info.begin(), info.end(), compare);
}

void solution () {
    int sumWeight = 0;
    int sumPrice = 0;
    int beforePrice = -1;

    for (int i = 0; i < N; ++i) {
        if (sumWeight < M) {
            if (beforePrice == info[i].second) sumPrice += info[i].second;
            else beforePrice = sumPrice = info[i].second;
        }
        else {
            if ((beforePrice != info[i].second) && (sumPrice >= info[i].second))
                beforePrice = sumPrice = info[i].second;
        }
        sumWeight += info[i].first;
    }

    if (sumWeight < M) cout << -1;
    else cout << sumPrice;
}

// 3, 

int main () {
    input();
    solution ();
    return 0;
}