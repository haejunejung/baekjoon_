#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

void move (int N, int start, int to) {
    v.push_back(make_pair(start, to));
}

void hanoi (int N, int start, int to, int via) {
    if (N == 1) {
        move (1, start, to);
        return;
    }

    hanoi(N-1, start, via, to);
    move (N, start, to);
    hanoi(N-1, via, to, start);
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    hanoi (N, 1, 3, 2);

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}